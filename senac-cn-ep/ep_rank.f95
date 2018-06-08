program ep
implicit none

    integer :: i , j
    double precision, dimension(:,:), allocatable :: entrada
    double precision, dimension(:,:), allocatable :: vetor_normal, mx
    double precision, dimension(:,:), allocatable :: matriz
    double precision :: m = 0.15
    double precision :: precisao = 0.000001
    double precision :: temp = 1
    integer :: dimensao = 4 !matriz de teste
    double precision :: n = 4.0
    allocate(vetor_normal(dimensao,1))
    allocate(mx(dimensao,1))
    allocate(entrada(dimensao,dimensao))
    allocate(matriz(dimensao, dimensao))

    do i=1, dimensao
        do j=1, dimensao
            matriz(i,j) = 1/n
        end do
    end do
    do i=1, dimensao
        vetor_normal(i,1) = 1/n
        mx(i,1) = (1/n) * m !mx e o valor fixo do vetor normal multiplicado por m utilizado nas iteracos
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

    ! M = (1-m)A + mS
    do i=1, dimensao
        do j=1, dimensao
            matriz(i,j) = ((1-m) * entrada(i,j)) + (m * matriz(i,j))
        end do
    end do    


    do while (temp-vetor_normal(1,1) > precisao )
        temp = MAXVAL(vetor_normal)
		vetor_normal = matmul(matriz,vetor_normal) !corresponde a Axk na formula 
		do i=1,dimensao
			vetor_normal(i,1) = ((1-m)*vetor_normal(i,1)) + mx(i,1)
		end do
	end do 

    do i=1,dimensao
		print *,vetor_normal(i,1)
	end do

end program ep