program ep
implicit none

    integer :: i , j , counter
    double precision, dimension(:,:), allocatable :: entrada
    double precision, dimension(:,:), allocatable :: vetor_normal
    double precision, dimension(:,:), allocatable :: matriz
    double precision :: m = 0.15
    integer :: dimensao = 4 !matriz de teste
    double precision :: n = 4.0
    allocate(vetor_normal(dimensao,1))
    allocate(entrada(dimensao,dimensao))
    allocate(matriz(dimensao, dimensao))

    do i=1, dimensao
        do j=1, dimensao
            matriz(i,j) = 1/n
        end do
    end do     
    
    entrada(1,1) = 0
	entrada(1,2) = 0
	entrada(1,3) = 1.0
	entrada(1,4) = 1.0/2
	entrada(2,1) = 1.0/3
	entrada(2,2) = 0
	entrada(2,3) = 0
	entrada(2,4) = 0
	entrada(3,1) = 1.0/3
	entrada(3,2) = 1.0/2
	entrada(3,3) = 0
	entrada(3,4) = 1.0/2
	entrada(4,1) = 1.0/3
	entrada(4,2) = 1.0/2
	entrada(4,3) = 0
	entrada(4,4) = 0


    do i=1, dimensao
        do j=1, dimensao
            matriz(i,j) = ((1-m) * entrada(i,j)) + (m * matriz(i,j))
        end do
    end do     


    ! vetor_normal = matmul(vetor_normal, vetor_normal)

    ! do i=1,dimensao
	! 	print *,vetor_normal(i,1)
	! end do

end program ep