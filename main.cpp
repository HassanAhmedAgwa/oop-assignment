#include <iostream>
#include <iomanip>
using namespace std;

struct matrix
{
  int** data;       // Pointer to 2-D array that will simulate matrix
  int row, col;
  void operator=  (const matrix& mat){

    row = mat.row;
    col = mat.col;

    for(int i=0; i < mat.row ; i++){
        for (int j=0; j < mat.col ; j++){
            data[i][j] = mat.data[i][j];
        }
    }
}

};

bool operator== (matrix mat1, matrix mat2);
bool operator!= (matrix mat1, matrix mat2);
matrix operator+  (matrix mat1, matrix mat2);
matrix operator+= (matrix& mat1, matrix mat2);
matrix operator-= (matrix& mat1, matrix mat2);
matrix operator+= (matrix& mat1, int scalar);
matrix operator-= (matrix& mat1, int scalar);
matrix transpose(matrix mat);
void operator++ (matrix& mat);
void operator-- (matrix& mat);
istream& operator>> (istream& in, matrix& mat);
ostream& operator<< (ostream& out, matrix mat);
void createMatrix (int row, int col, int num[], matrix& mat);
bool isSquare (matrix mat);
bool isIdentity (matrix mat);
bool isSymetric (matrix mat);


int main()
{
    int data1 [] = {1,2,3,4,1,6};
    int data2 [] = {13,233,3,4,5,6,8,8,9};
    int data3 [] = {10,100,10,100,10,100,10,100};

    matrix mat1, mat2, mat3;
    createMatrix (3, 2, data1, mat1);
    createMatrix (3, 3, data2, mat2);
    createMatrix (3, 3, data2, mat3);
    //bool same = mat1==mat1;
    /*if (mat1 == mat2){
        cout << "The given matrices are identical." <<endl;
    }
    else{
        cout << "The given matrices are different." <<endl;
    }*/

    //cout << (mat1 != mat2) << endl;

    // mat3 = mat1 + mat2;
     cin >> mat3 >> mat1;

     //mat3 = (mat1 += 10);
    //--mat1;
     cout<< mat3 << mat1 << endl  ;


}


void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (int i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat.data[i][j] = num[i * col + j];
}
/**************************************************************************/
matrix operator+  (matrix mat1, matrix mat2){
    matrix result;
    if (mat1.row == mat2.row && mat1.col == mat2.col){
        int rows = mat1.row, cols = mat1.col;
        int arr[] = {};

        createMatrix(rows, cols,arr, result);

        for(int i=0; i < mat1.row ; i++){
            for (int j=0; j < mat1.col ; j++){
                result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
            }
        }
    }

    return result;
}
/**************************************************************************/
matrix operator+= (matrix& mat1, matrix mat2){
    if (mat1.row == mat2.row && mat1.col == mat2.col){
        for(int i=0; i < mat1.row ; i++){
            for (int j=0; j < mat1.col ; j++){
                mat1.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
            }
        }
    }
    return mat1;
}
/**************************************************************************/
matrix operator-= (matrix& mat1, matrix mat2){
    if (mat1.row == mat2.row && mat1.col == mat2.col){
        for(int i=0; i < mat1.row ; i++){
            for (int j=0; j < mat1.col ; j++){
                mat1.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
            }
        }
    }
    return mat1;
}
/**************************************************************************/
matrix operator+= (matrix& mat1, int scalar){
    if (mat1.row > 0 && mat1.col > 0){
        for(int i=0; i < mat1.row ; i++){
            for (int j=0; j < mat1.col ; j++){
                mat1.data[i][j] = mat1.data[i][j] + scalar;
            }
        }
    }
    return mat1;
}
/**************************************************************************/
matrix operator-= (matrix& mat1, int scalar){
    if (mat1.row > 0 && mat1.col > 0){
        for(int i=0; i < mat1.row ; i++){
            for (int j=0; j < mat1.col ; j++){
                mat1.data[i][j] = mat1.data[i][j] - scalar;
            }
        }
    }
    return mat1;
}
/**************************************************************************/
void operator++ (matrix& mat){
    mat += 1;
}
/**************************************************************************/
void operator-- (matrix& mat){
    mat -= 1;
}
/**************************************************************************/
ostream& operator<< (ostream& out, matrix mat){
    out << endl << " Matrix [" << mat.row << "][" << mat.col << "] = " << endl;
    for(int i=0; i < mat.row ; i++){
        for (int j=0; j < mat.col ; j++){
            if (j == mat.col-1){
                out << " | " << mat.data[i][j] << " |";
            }
            else{
                out << " | " << mat.data[i][j];
            }

        }
        out << endl;
    }
    return out;
}
/**************************************************************************/
istream& operator>> (istream& in, matrix& mat){
    in >> mat.row;
    in >> mat.col;

    for (int i=0; i < mat.row  ; i++)
        for (int j=0; j < mat.col ; j++)
            in >> mat.data[i][j];

    return in;
}
/**************************************************************************/
bool operator== (matrix mat1, matrix mat2){

    if (mat1.row != mat2.row || mat1.col != mat2.col) return false;

    for(int i=0; i < mat1.row ; i++){
        for (int j=0; j < mat1.col ; j++){
            if (mat1.data[i][j] != mat2.data[i][j])
                return false;
        }
    }
    return true;
}
/**************************************************************************/
bool operator!= (matrix mat1, matrix mat2){
    bool  y=false;
if (mat1.row != mat2.row || mat1.col != mat2.col) return true;

    for(int i=0; i < mat1.row ; i++){
        for (int j=0; j < mat1.col ; j++){
            if (mat1.data[i][j] != mat2.data[i][j])
                y= true;
        }
    }
    return y;
}
/**************************************************************************/
bool isSquare (matrix mat){

    return mat.row == mat.col;
}
/**************************************************************************/
matrix transpose(matrix mat){
    int arr []={};
    matrix x;
    createMatrix(mat.col, mat.row,arr,x);
    for(int i = 0 ; i < mat.row ; i++)
        for(int j = 0 ; j < mat.col ; j++)
            x.data[j][i]=mat.data[i][j];

return  x;

}
/**************************************************************************/
bool isIdentity (matrix mat)
{
    if(!isSquare(mat)) return false;

    for(int i = 0 ; i < mat.row ; i++)
        for(int j=0; j<mat.col; j++)
        {
            if(i==j)
            {
                if(mat.data[i][j]!=1)
                {
                    return false;
                }
            }
            else
            {
                if(mat.data[i][j]!=0)
                {
                    return false;
                }
            }
        }
    return true;
}

/**************************************************************************/
bool isSymetric (matrix mat)
{
    if(!isSquare(mat)) return false;

    for (int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            if(j!=i)
            {
                if(mat.data[i][j]!=mat.data[j][i])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
/***************************************************************************/
