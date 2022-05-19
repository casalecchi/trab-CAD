program main

    real, allocatable :: x(:)
    real, allocatable :: b(:)
    real, allocatable :: mat(:, :)
    character(100) :: nchar
    integer :: n
    integer :: i
    real :: start, finish

    if (command_argument_count().ne.1) then
        stop "pare"
    endif

    call get_command_argument(1, nchar)   

    read (nchar,*)n

    call cpu_time(start)

    allocate(x(n))
    allocate(b(n))
    allocate(mat(n, n))

    call random_number(mat)
    call random_number(x)

    outer_loop: do j = 1, n
        inner_loop: do i = 1, n
            b(i) = b(i) + mat(i, j) * x(j)
        end do inner_loop
    end do outer_loop

    deallocate(x)
    deallocate(b)
    deallocate(mat)

    call cpu_time(finish)
    print *, finish - start

    open(unit=40, file='dados_f_trocado.csv', action='write', position='append')
    write(40,'(g0.7","g0.7)') n, finish-start
    
    close(40)

end program main