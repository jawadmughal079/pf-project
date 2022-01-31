#include <iostream>
#include <fstream>
using namespace std;
void whatIsProject();                 // this function about what is project
void selectInputFromFileOrUserMenu(); // this function is about you want to input from file or user
int selectFilOrUser();                // this function for select option by user
void whatTypeOfuserInputSelected(int selectOption, int **arr, int &row, int &col);
void input(int **arr, int &row, int &col); // this function use for simple input
void output(int **arr, int row, int col);  // this function use for simple output
void inputFromFileProcess(int **arr, int row, int col, ifstream &readFromFile);
void outputFromFileProcess(int **arr, int row, int col, ofstream &writeIntoFile);
void sumOfMatrixIs(int **arr, int row, int col);
void productOfMatrixIs(int **arr, int row, int col);
void rowWiseProduct(int **arr, int row, int col);
void colWiseProduct(int **arr, int row, int col);
void averageOrWholeMatrix(int **arr, int row, int col);
void shortingIn2DArrayRowWise(int **arr, int row, int col);
void shortingIn2DArrayColumnWise(int **arr, int row, int col);
void scalarMatrixAdditon(int **arr, int row, int col);
void additionOfTwomatrix(int **arr, int **arr2, int row, int col);
void inputOf2matrix(int **arr2, int &row, int &col);
void scalerMatrixSubscription(int **arr, int row, int col);
void mainMenu();
int main()
{
    int counter = 0; // this is use for count value from file
    int **arr = nullptr;
    int row = 0;
    int col = 0;
    int **arr2 = nullptr;
    int selectOption = 0; // this is use for get menu option what is end user select the option
    arr = new int *[row];
    arr2 = new int *[row];
    whatIsProject();
    selectInputFromFileOrUserMenu();
    selectOption = selectFilOrUser();
    whatTypeOfuserInputSelected(selectOption, arr, row, col);
    while (true)
    {
        mainMenu();
        selectOption = selectFilOrUser();
        if (selectOption != 1 || selectOption != 2 || selectOption != 3 || selectOption != 4 || selectOption != 5 || selectOption != 6 || selectOption != 7 || selectOption != 8 || selectOption != 9 || selectOption != 10 || selectOption != 11 || selectOption != 12 || selectOption != 13 || selectOption != 14 || selectOption != 15 || selectOption != 16 || selectOption != 17 || selectOption != 0)
        {

            while (selectOption != 1 && selectOption != 2 && selectOption != 3 && selectOption != 4 && selectOption != 5 && selectOption != 6 && selectOption != 7 && selectOption != 8 && selectOption != 9 && selectOption != 10 && selectOption != 11 && selectOption != 12 && selectOption != 13 && selectOption != 14 && selectOption != 15 && selectOption != 16 && selectOption != 17 && selectOption != 0)
            {
                cout << "----------------------------------------------------------------------------------------\n";
                cout << "\t\t\tYOU ENTER INTO WRONG INPUT\n\t\t     PLEASE ENTER AGIAIN VALID OPTION ";
                cout << "\n----------------------------------------------------------------------------------------\n";
                selectOption = selectFilOrUser();
            }
        }
        if (selectOption == 0)
        {
            cout << "============================================================================================" << endl;
            cout << "  Thank you for using system.......:)" << endl;
            cout << "\n";
            cout << "                         System was developed by : JAWAD MUGHAL L1S21BSSE0079" << endl;
            cout << "============================================================================================" << endl;
            break;
        }
        if (selectOption == 1)
        {
            input(arr, row, col);
            sumOfMatrixIs(arr, row, col);
        }
        if (selectOption == 2)
        {
            input(arr, row, col);
            productOfMatrixIs(arr, row, col);
        }
        if (selectOption == 3)
        {
            input(arr, row, col);
            rowWiseProduct(arr, row, col);
        }
        if (selectOption == 4)
        {
            input(arr, row, col);
            colWiseProduct(arr, row, col);
        }
        if (selectOption == 5)
        {
            input(arr, row, col);
            averageOrWholeMatrix(arr, row, col);
        }
        if (selectOption == 6)
        {
            input(arr, row, col);
            shortingIn2DArrayRowWise(arr, row, col);
            output(arr, row, col);
        }
        if (selectOption == 7)
        {
            input(arr, row, col);
            shortingIn2DArrayColumnWise(arr, row, col);
            output(arr, row, col);
        }
        if (selectOption == 8)
        {
            input(arr, row, col);
            scalarMatrixAdditon(arr, row, col);
            output(arr, row, col);
        }
        if (selectOption == 9)
        {
            input(arr, row, col);
            output(arr, row, col);
            inputOf2matrix(arr2, row, col);
            output(arr, row, col);
            additionOfTwomatrix(arr, arr2, row, col);
        }
        if (selectOption == 10)
        {
            input(arr, row, col);
            scalerMatrixSubscription(arr, row, col);
            output(arr, row, col);
        }
    }

    return 0;
}
void mainMenu()
{
    cout << "\n====================================================================" << endl;
    cout << "  ----------------------------------------              " << endl;
    cout << "   |               MENUE              |    " << endl;
    cout << "  ----------------------------------------              " << endl;
    cout << "1.  Sum of Matrix (sum of all values) \n";
    cout << "2.  Product of Matrix (product of all values) \n";
    cout << "3.  Row-wise Average \n";
    cout << "4.  Column-wise Average \n";
    cout << "5.  Average or whole Matrix \n";
    cout << "6.  Row-wise sorting of Matrix \n";
    cout << "7.  Column-wise sorting of Matrix \n";
    cout << "8.  Scalar Matrix Addition \n";
    cout << "9.  Addition of two Matrices \n";
    cout << "10. Scalar Matrix Subtraction \n";
    cout << "11. Subtraction of two Matrices \n";
    cout << "12. Scalar Matrix Multiplication \n";
    cout << "13. Multiplication of two Matrices \n";
    cout << "14. Scalar Matrix Division \n";
    cout << "15. Matrix transpose \n";
    cout << "16. Matrix determinant \n";
    cout << "17. Matrix Inverse \n";
    cout << "Enter your choice: ";

    cout << "\n";
    cout << "=============================================================================================" << endl;
}
// this functin about what is project
void whatIsProject()
{
    cout << "\n----------------------------------------------------------------------------------------\n";
    cout << " \t\t\t\tMATRIX MANIPULATOR";
    cout << "\n----------------------------------------------------------------------------------------\n";
}
// this function is about you want to input from file or user
void selectInputFromFileOrUserMenu()
{
    cout << "\n----------------------------------------------------------------------------------------\n";
    cout << " \t\t\tPRESS 1-ENTER MATRIX PERSONALLY\n";
    cout << " \t\t\t\t     OR\n";
    cout << " \t\t   PRESS 2-THOUGH FILES OF THEIR CHOOSING";
    cout << "\n----------------------------------------------------------------------------------------\n";
}
int selectFilOrUser()
{
    int select = 0;

    cout << " SELECT OPTION :-";
    cin >> select;

    return select;
}
void whatTypeOfuserInputSelected(int selectOption, int **arr, int &row, int &col)
{
    if (selectOption != 1 || selectOption != 2)
    {
        while (selectOption != 1 && selectOption != 2)
        {
            cout << "----------------------------------------------------------------------------------------\n";
            cout << "\t\t\tYOU ENTER INTO WRONG INPUT\n\t\t     PLEASE ENTER AGIAIN VALID OPTION ";
            cout << "\n----------------------------------------------------------------------------------------\n";
            selectOption = selectFilOrUser();
        }
    }
    if (selectOption == 1 || selectOption == 2)
    {
        if (selectOption == 1)
        {
            cout << "----------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\tTHANKS YOU \n\t\tNOW YOU ENTER INTO USER INPUT OPTION ";
            cout << "\n----------------------------------------------------------------------------------------\n";

            // input(arr, row, col);
            // output(arr, row, col);
        }
        else if (selectOption == 2)
        {

            int selectOutput = 0;
            char filename[30], ch, str[1000];
            int tot = 0, i = 0, tot_lines = 0, tot_spaces = 0;

            cout << "----------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\tTHANKS YOU \n\t\t\tNOW YOU ENTER INTO FILE INPUT OPTION ";
            cout << "\n----------------------------------------------------------------------------------------\n";
            ifstream readFromFile;
            cout << "Enter the Name of File: ";
            cin >> filename;
            readFromFile.open(filename, ifstream::in);
            if (!readFromFile)
            {
                cout << endl
                     << "FILE DOESN'T EXIST OR ACCESS DENIED!";
            }

            while (readFromFile >> noskipws >> ch)
            {
                if (ch == '\n')
                {
                    break;
                }
                if (ch == ' ')
                {
                    tot_spaces++;
                }
                tot++;
            }
            while (!readFromFile.eof())
            {
                readFromFile.getline(str, 1000);
                tot_lines++;
            }
            tot_lines++;
            readFromFile.close();

            cout << endl
                 << "Total Number of Lines = " << tot_lines;
            cout << endl;
            cout << endl
                 << "Total Number of Elements = " << tot;
            cout << endl;
            cout << endl
                 << "Total Number of tot_spaces = " << tot_spaces;
            cout << endl;

            row = tot_lines;
            col = tot - tot_spaces;
            cout << " ROW IS THIS : " << row;
            cout << endl;
            cout << " col IS THIS : " << col;
            cout << endl;
            inputFromFileProcess(arr, row, col, readFromFile);

            ofstream writeIntoFile;
            writeIntoFile.open("writeFile.txt");

            cout << "----------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\t\tTHANKS YOU \n\t\t\tNOW YOU WANT TO SHOW OUTPUT INTO CONSOLE  PRESS 1 \n\t\t\t\t\t\tOR\n \t\t\t\t\tPRESS 2 FILE ";
            cout << "\n----------------------------------------------------------------------------------------\n";
            selectOutput = selectFilOrUser();
            if (selectOutput != 1 || selectOutput != 2)
            {

                while (selectOutput != 1 && selectOutput != 2)
                {
                    cout << "----------------------------------------------------------------------------------------\n";
                    cout << "\t\t\tYOU ENTER INTO WRONG INPUT\n\t\t     PLEASE ENTER AGIAIN VALID OPTION ";
                    cout << "\n----------------------------------------------------------------------------------------\n";
                    selectOutput = selectFilOrUser();
                }
            }
            if (selectOutput == 1 || selectOutput == 2)
            {

                if (selectOutput == 1)
                {
                    output(arr, row, col);
                }
                if (selectOption == 2)
                {

                    outputFromFileProcess(arr, row, col, writeIntoFile);
                }
            }
        }
    }
}
void input(int **arr, int &row, int &col)
{
    cout << " ENTER A ROW PLEASE : ";
    cin >> row;
    cout << " ENTER A col PLEASE : ";
    cin >> col;
    cout << "\n\t\t\tENTER A VALUE INTO ARRAY\t  \n";
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "A[" << i << "][" << j << "] : ";
            cin >> arr[i][j];
        }
    }
}
void inputOf2matrix(int **arr2, int &row, int &col)
{
    cout << "\n===============================================================================\n";
    cout << "\t\t\t\t ENTER THE VALUES \n";
    cout << "\n===============================================================================\n";

    for (int i = 0; i < row; i++)
    {
        arr2[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "A[" << i << "][" << j << "] : ";
            cin >> arr2[i][j];
        }
    }
}
void output(int **arr, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "A[" << i << "][" << j << "] : ";
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}
void inputFromFileProcess(int **arr, int row, int col, ifstream &readFromFile)
{
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            readFromFile >> arr[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "\n----------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\tREAD FILE SUCCESSFULLY";
    cout << "\n----------------------------------------------------------------------------------------\n";
    cout << endl;
}
void outputFromFileProcess(int **arr, int row, int col, ofstream &writeIntoFile)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            writeIntoFile << arr[i][j];
            writeIntoFile << " ";
        }
        writeIntoFile << endl;
    }
    cout << "\n----------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\tOUTPUT WRITE INTO FILE SUCCESSFULLY";
    cout << "\n----------------------------------------------------------------------------------------\n";
}

void sumOfMatrixIs(int **arr, int row, int col)
{

    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
    }
    cout << " SUM OF MATRIX IS THIS : " << sum;
}
void productOfMatrixIs(int **arr, int row, int col)
{
    int product = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            product *= arr[i][j];
        }
    }
    cout << " PRODUCT OF MATRIX IS THIS : " << product;
}
void rowWiseProduct(int **arr, int row, int col)
{
    int sum = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
    }
    cout << " ROW WISE AVERAGE: " << float(sum) / float(row);
}
void colWiseProduct(int **arr, int row, int col)
{
    int sum = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
    }
    cout << " COLUMN WISE AVERAGE: " << float(sum) / float(col);
}
void averageOrWholeMatrix(int **arr, int row, int col)
{
    int sum = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
    }
    cout << " COLUMN WISE AVERAGE: " << float(sum) / float(col) + float(row);
}
void shortingIn2DArrayRowWise(int **arr, int row, int col)
{

    cout << "\nshortingIn2DArrayRowWise\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < col - j - 1; k++)
            {
                if (arr[i][k] > arr[i][k + 1])
                {
                    int temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }
}
void shortingIn2DArrayColumnWise(int **arr, int row, int col)
{

    cout << "\nshortingIn2DArrayRowWise\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < col - j - 1; k++)
            {
                if (arr[k][i] > arr[k + 1][i])
                {
                    int temp = arr[k][i];
                    arr[k][i] = arr[k + 1][i];
                    arr[k + 1][i] = temp;
                }
            }
        }
    }
}
void scalarMatrixAdditon(int **arr, int row, int col)
{
    int num = 0;
    cout << "  ENTER A NUMBER YOU WANT TO ADD : ";
    cin >> num;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = arr[i][j] + num;
        }
    }
}
void additionOfTwomatrix(int **arr, int **arr2, int row, int col)
{

    int sum[10][10] = {0, 0};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum[i][j] = arr[i][j] + arr2[i][j];
            cout << sum[i][j] << "  ";
        }
    }
    cout << "\n ADDITION OF TWO MATRIX IS : \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "A[" << i << "][" << j << "] : ";
            cout << sum[i][j] << "  ";
        }
        cout << endl;
    }
}
void scalerMatrixSubscription(int **arr, int row, int col)
{
    int sub = 0;
    cout << "Enter number for scalar matrix Subtraction :";
    cin >> sub;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = arr[i][j] - sub;
        }
    }
}