subroutine teste_rank(retorno, entrada, dimensao)
    ! =====================================================
    ! teste
    ! =====================================================
    integer :: i , j, parada
    ! double precision, dimension(:,:), allocatable :: entrada
    double precision, dimension(:,:), allocatable :: vetor_normal, mx
    double precision, dimension(:,:), allocatable :: matriz
    integer, intent(in) :: dimensao
    double precision, intent(in) :: entrada(dimensao,dimensao)
    double precision, intent(out)  :: retorno(dimensao,1)
    double precision :: m = 0.15
    double precision :: precisao = 0.00001
    double precision :: temp = 1
    ! integer :: dimensao !matriz de teste
    double precision :: n
    allocate(vetor_normal(dimensao,1))
    allocate(mx(dimensao,1))
    ! allocate(entrada(dimensao,dimensao))
    allocate(matriz(dimensao, dimensao))
    n = dimensao/1.0
    parada = 1
     ! seta matriz S com todas entradas = 1/n
    do i=1, dimensao
        do j=1, dimensao
            matriz(i,j) = 1/n
        end do
    end do
    do i=1, dimensao
        vetor_normal(i,1) = 1/n
        mx(i,1) = (1/n) * m !mx e o valor fixo do vetor normal multiplicado por m utilizado nas iteracos
    end do  

    ! M = (1-m)A + mS
    do i=1, dimensao
        do j=1, dimensao
            matriz(i,j) = ((1-m) * entrada(i,j)) + (m * matriz(i,j))
        end do
    end do    

    ! calculo de vetor de pesos xk+1 = (1-m)Axk+mx0
    do while (temp-vetor_normal(1,1) > precisao )
        if(parada >= 100000000) THEN
            exit
        end if
        temp = MAXVAL(vetor_normal)
        vetor_normal = matmul(matriz,vetor_normal) !corresponde a Axk na formula 
        do i=1,dimensao
            vetor_normal(i,1) = ((1-m)*vetor_normal(i,1)) + mx(i,1)
        end do
        parada = parada + 1
    end do 

    do i=1,dimensao
       retorno(i,1) =vetor_normal(i,1)
    end do
end subroutine
