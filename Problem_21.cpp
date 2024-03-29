//
// Problem_21.cpp
// 
// Created by Aurimas A. Nausedas on 10/09/19. 
// Update by Aurimas A. Nausedas onn 10/31/21.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <conio.h>


class Matrix;
class Vector;

class Vector
{
public:
    Vector(){n = 0; x = 0;};
    Vector(int n){alokacija(n);}; | alokacija = allocation
    Vector(char* failas);
    Vector(Vector& A);

    ~Vector();

    void alokacija(int ln);
    void clear();
    void out(char* s);
    void operator= (Vector& A);
    double& operator[] (int i);
    void naujas(int ln);


    friend Vector operator +(Vector& A, Vector& B);
    friend Vector operator *(Vector& A, Vector& B);
    friend Matrix operator *(const Matrix& M, const Vector& V);
    //friend Matrix Matrix(Vector& A);

private:
    int n; // Komponenciu skaicius | Number of components
    double *x; // Rodykle i komponenciu masyva | Arrow to an array of components
};

//-----------------------------------------------
//-----------------------------------------------
void Vector::alokacija(int ln)
{
    n = ln;
    x = new double[n];
    assert(x != 0);
    clear();
    //printf("Allocating: %p\n" , x);
}

//-----------------------------------------------
void Vector::clear()
{
    for (int i = 0; i < n; i++) x[i] = 0.0;
}

//-----------------------------------------------
Vector::Vector(char* failas)
{
    FILE* in; // rodykle i struktura FILE | arrow in FILE structure
              // FILE reikalinga buferiui valdyti | FILE is required to control the buffer
    int n;
    double dl;
    //printf("FILE: %s",failas);
    in = fopen(failas,"rt");
    assert(in != 0);

    fscanf(in,"%d\n",&n);
    alokacija(n);

    for (int i = 0; i < n; i++)
    {
        fscanf(in, "%lf",&dl);
        x[i]=dl;
    }
    fclose(in);
}

//-----------------------------------------------

Vector::Vector(Vector& A)
{
    alokacija(A.n);
    for (int i = 0; i < n; i++) x[i] = A.x[i];
}

//-----------------------------------------------

Vector::~Vector()
{
    //printf ("Deleting: %p\n",x);
    if(x != NULL) delete []x;
}

//-----------------------------------------------
void Vector::out(char* s)
{
    printf("%s:\n", s);
    if(x == 0)
    {
        printf("Empty\n\n");
        return;
    }
    for (int i = 0; i < n; i++) printf("%8.4f", x[i]);
    printf("\n\n");
}

//-----------------------------------------------

void Vector::operator= (Vector& A)
{
    if(n != A.n) naujas(A.n);
    for (int i = 0; i < n; i++) x[i] = A.x[i];
}

//-----------------------------------------------
void Vector::naujas(int ln)
{
    if (n == ln) return;
    if (x != 0) delete []x;

    // ar cia kartais neturi buti ln? Knygoje: alokacija(n) | don't you have to be here sometimes? In the book: allocation (n)
    // mano supratimu turi buti ln | In my understanding must be ln
    // visa ideja yra peralokuoti toko dydzio vector objekto | the whole idea is to reallocate a vector object of that size
    // x masyva, kad graziai tilptu rezultatas | x array to fit nicely the result
    alokacija(ln);
}

//-----------------------------------------------

Vector operator+ (Vector& A, Vector& B)
{
    if (A.n != B.n)
    {
        printf("Vector class error: bad index\n");
        exit(1);
    }
    Vector Temp(A.n);
    for (int i = 0; i < A.n; i++)
    {
        Temp.x[i] = A.x[i] + B.x[i];
    }
    return Temp;
}

//-----------------------------------------------

// vektoriu skaliarine sandauga
Vector operator *(Vector& A, Vector& B)
{
	if (A.n != B.n)
    {
        printf("Vector class error: bad index\n");
        exit(1);
    }
    Vector Temp(1);
    double mult = 0;
    for (int i = 0; i < A.n; i++) mult += A.x[i] * B.x[i];
    Temp.x[0] = mult;
    return Temp;
}

//-----------------------------------------------
double& Vector::operator[] (int i)
{
    if (i < 0 || i >= n)
    {
        printf("Vector index error!\n");
        exit(1);
    }
    return x[i];
}

//-----------------------------------------------
//-----------------------------------------------








//-----------------------------------------------
//-----------------------------------------------

class Matrix
{
public:
    Matrix(){n = 0; m = 0; x = 0;};
    Matrix(int n, int m){alokacija(n,m);};
    Matrix(char* failas);
    Matrix(const Matrix& A);
    //Matrix(Vector& A);

    ~Matrix();

    void alokacija(int ln, int lm);
    void clear();
    void out(char* s);
    void get_p(){printf("adresas: %p\n",x);};
    void operator= (const Matrix& A);
    double& iloc(int i,int j);
    void naujas(int ln, int lm);
    void T(); // transpozicijai | transposition


    friend Matrix operator +(const Matrix& A, const Matrix& B);
    friend Matrix operator *(const Matrix& A, const Matrix& B);
    friend Matrix operator *(const Matrix& M, const Vector& V);

private:
    int 	n, //eiluciu sk
    		m; //stulpeliu sk

    double **x; // Rodykle i komponenciu masyva | Arrow to an array of components
};


//-----------------------------------------------
void Matrix::alokacija(int ln, int lm)
{
    n = ln;
    m = lm;

    x = new double*[n];
    assert(x != 0);

    for (int i = 0; i < n; i++)
    {
        x[i] = new double(m);
        assert(x[i] != 0);
    }


    clear();
    //printf("Allocating: %p\n" , x);
}

//-----------------------------------------------
void Matrix::clear()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) x[i][j] = 0.0;
    }
}



//-----------------------------------------------
Matrix::Matrix(char* failas)
{
    FILE* in; // rodykle i struktura FILE | arrow in the FILE structure
              // FILE reikalinga buferiui valdyti | FILE is required to control the buffer
    int n,m;
    double dl;
    printf("\nFILE: %s\n\n",failas);
    in = fopen(failas,"rt");
    assert(in != 0);

    fscanf(in,"%d%d\n",&n,&m);
    alokacija(n,m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fscanf(in, "%lf",&dl);
            x[i][j]=dl;
        }

    }
    //printf("sudejus perves X xo adresas = %p\n",x);
    fclose(in);
}

//-----------------------------------------------

Matrix::Matrix(const Matrix& A)
{
    //printf("--------------------------------------\n");
    alokacija(A.n,A.m);
    //printf("consrtucting n = %d, m = %d\n",n,m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            x[i][j] = A.x[i][j];
            //printf("%d,%d = %.2f/%.2f      ",i,j,A.x[i][j],x[i][j]);
            //printf("%d,%d = %5.2f      ",i,j,A.iloc(i,j));
        }
        printf("\n");
    }
    //printf("--------------------------------------\n");

}

//-----------------------------------------------
/*
// konstruktorius paversti vektoriu stulpeliu (matrica) | convert constructor to vector column (matrix)
Matrix::Matrix(Vector& A)
{
    alokacija(A.n,1);
    for (int i = 0; i < n; i++) x[i][0] = A.x[i];

}
 */

//-----------------------------------------------

Matrix::~Matrix()
{
    //printf ("Deleting: %p\n",x);
    if(x != NULL)
    {
        for (int i = 0; i < n; i++) delete []x[i];
        delete []x;
    }

}

//-----------------------------------------------
void Matrix::out(char* s) // veikia | works
{
    printf("%s:\n", s);
    if(x == 0)
    {
        printf("Empty\n\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) printf("%8.4f    ", x[i][j]);
        printf("\n");
    }
    printf("\n");
}

//-----------------------------------------------

void Matrix::operator= (const Matrix& A)
{
    if(n != A.n || m != A.m) naujas(A.n,A.m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) x[i][j] = A.x[i][j];
    }
}

//-----------------------------------------------
void Matrix::naujas(int ln, int lm)
{
    if (n == ln && m == lm) return;
    if (x != 0)
    {
        for (int i = 0; i < n; i++) delete []x[i];
        delete []x;
    }

    alokacija(ln,lm);
}

//-----------------------------------------------

Matrix operator+ (const Matrix& A, const Matrix& B)
{
    if (A.n != B.n || A.m != B.m)
    {
        printf("Error, cannot add matrix %dx%d and %dx%d\n",A.n,A.m,B.n,B.m);
        Matrix Temp;
        return Temp;
    }

    Matrix Temp(A.n, A.m);
    for (int i = 0; i < A.n; i++)
    {
        for (int j = 0; j < A.m; j++) Temp.x[i][j] = A.x[i][j] + B.x[i][j];

    }
    return Temp;
}


//-----------------------------------------------

// transpozicija | transposition
void Matrix::T()
{
    if (x == 0)
    {
        printf("trying to transpose empty matrix");
        exit(1);
    }

    Matrix Temp(m, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) Temp.x[j][i] = x[i][j];
    }

    //isvalau x: | Deleting x:
    //printf ("Deleting: %p\n",x);
    for (i = 0; i < n; i++) delete []x[i];
    delete []x;

    // sukonstruoju nauja x: | Constructing new x:
    //Matrix(Temp) // gal veiks?
    alokacija(Temp.n,Temp.m);
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) x[i][j] = Temp.x[i][j];
    }

    //temp turi susinaukinti uz skliausto | temp must delete itself after the parentheses

}

//-----------------------------------------------

// matricu sandauga | matrix multiplication
Matrix operator *(const Matrix& A, const Matrix& B)
{
    if (A.m != B.n)
   y
        printf("Error, cannot multiplby matrixes %dx%d ir %dx%d\n",A.n,A.m,B.n,B.m);
        Matrix Temp;
        return Temp;
    }


    Matrix Temp(A.n,B.m);
    for (int i = 0; i < A.n; i++)
    {
        for (int j = 0; j < B.m; j++)
        {
            double mult = 0;
            for (int k = 0; k < A.m; k++) mult += A.x[i][k] * B.x[k][j];
            Temp.x[i][j] = mult;
        }
    }
    return Temp;
}

// matricos ir vektoriaus sandauga | product of matrix and vector
Matrix operator *(const Matrix& M, const Vector& V)
{
    // 1 zingsnis: pasidaryti matrica is vectoriaus V | Step 1: Make a matrix from the vector V
    if (M.m != V.n)
    {
        printf("Error, M and V cannot be multiplied by dimensions %dx%d and %d\n",M.n,M.m,V.n);
        Matrix Temp;
        return Temp;
    }

    Matrix VM(V.n,1); // stulpelis | column
    for (int i = 0; i < V.n; i++)
    {
        VM.x[i][1] = V.x[i];
    }

    // antras zingsnis = tiesiog panadoju matricu sandauga | step two = just multiply the matrix
    Matrix Temp;
    Temp = M * VM;
    return Temp;


}


//-----------------------------------------------
double& Matrix::iloc(int i,int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        printf("Vector index error!\n");
        exit(1);
    }
    return x[i][j];
}

//-----------------------------------------------
//-----------------------------------------------




//-----------------------------------------------
//-----------------------------------------------


int main()
{
	clrscr();
    Vector  A("c:\\TC\\BIN\\p21_dat\\v_a.dat"),
            B("c:\\TC\\BIN\\p21_dat\\v_b.dat"),
            C("c:\\TC\\BIN\\p21_dat\\v_c.dat"),
            D;

    A.out("A");
    A[0] = 10.;
    A.out("A");
    B.out("B");
    C.out("C");

    D = A + B + C;
    D.out("D=A+B+C");

    Vector F;
    F = A * B;


    //Vector F((A * B));
    F.out("F=A*B");

    getch();
    clrscr();

    //matricos | matrices
    Matrix  X("c:\\TC\\BIN\\p21_dat\\m_x.dat"),
            Xrep("c:\\TC\\BIN\\p21_dat\\m_x.dat"),
            Y("c:\\TC\\BIN\\p21_dat\\m_y.dat");
            //Z;

    getch();
    clrscr();

    //transpozicija | transposition
    printf("Transpozicija\n\n");
    Xrep.out("X");
    Xrep.T();
    Xrep.out("X transposed");
    Xrep.T();
    getch();
    clrscr();

    // sandauga matricu | matrices multiplication
    printf("Matrices multiplication 1\n\n");
    X.out("X");
    Y.out("Y");
    Matrix Z,W;
    W = Y * X;
    W.out("W=Y*X");
    getch();
    clrscr();

    printf("Matrices multiplication 2\n\n");
    X.out("X");
    Y.out("Y");
    Z = X * Y;
    Z.out("Z=X*Y");
    getch();
    clrscr();

    // suma matricu:
    printf("Matrices sum 1\n\n");
    X.out("X");
    Y.out("Y");
    Matrix Sf;
    Sf = X + Y;
    Sf.out("Sf=X+Y");
    getch();
    clrscr();

    printf("Matrices sum 2\n\n");
    X.out("X");
    Xrep.out("Xrep");
    Matrix S;
    S = X + Xrep;
    S.out("S=X+Xrep");
    getch();
    clrscr();

    //Matricos ir vectoriaus sandauga | Multiplication of matrix and vector
    printf("Multiplication of matrix and vector 1\n\n");
    A.out("A");
    X.out("X");
    Matrix MVf;
    MVf = X * A;
    MVf.out("MV=X*A");
    getch();
    clrscr();

    printf("Multiplication of matrix and vector 2\n\n");
    X.T();
    A.out("A");
    X.out("Xt");
    Matrix MV;
    MV = X * A;
    MV.out("MV=Xt*A");
    getch();
    clrscr();

    /*
    X.get_p();
    X.out("X");
    X.get_p();
    printf("X.iloc(0,0) = %.2f\n",X.iloc(0,0));
    X.get_p();

    getch();
    clrscr();

    X.get_p();


    getch();
    clrscr();

    //X.T();
    //X.out("Xt");
    //Y.out("Y");
    //Z = X;// + Xrep;
    //Z.out("Z");
    //printf("X.iloc(0,0) = %.2f\n",X.iloc(0,0));
    X.get_p();
    Matrix Q(X);
    X.get_p();
    Q.out("Q");
    printf("X.iloc(0,0) = %.2f\n",X.iloc(0,0));
    getch();

     */

    return 0;
}
