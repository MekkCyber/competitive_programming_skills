/*
Consider a matrix where each cell contains either a  or a . Any cell containing a  is called a filled cell. Two cells are said to be 
connected if they are adjacent to each other horizontally, vertically, or diagonally.
Given an  matrix, find and print the number of cells in the largest region in the matrix. Note that there may be more than one region in the matrix.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int dfs(vector<vector<int>> matrix,vector<vector<int>>& visited, int n, int m, int i, int j);

int connectedCell(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    int max_ = 0;
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            if (matrix[i][j]==1 && !visited[i][j]){
                int size = dfs(matrix,visited,n,m,i,j);
                max_ = max(size,max_);
            }
        }
    }
    return max_;
}

int dfs(vector<vector<int>> matrix,vector<vector<int>>& visited, int n, int m, int i, int j){
    visited[i][j] = 1;
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
    if (i>0 && matrix[i-1][j]==1 && !visited[i-1][j]) a = dfs(matrix,visited,n,m,i-1,j);
    if (j>0 && matrix[i][j-1]==1 && !visited[i][j-1]) b = dfs(matrix,visited,n,m,i,j-1);
    if (i+1<m && matrix[i+1][j]==1 && !visited[i+1][j]) c = dfs(matrix,visited,n,m,i+1,j);
    if (j+1<n && matrix[i][j+1]==1 && !visited[i][j+1]) d = dfs(matrix,visited,n,m,i,j+1);
    
    if (i>0 && j>0 && matrix[i-1][j-1]==1 && !visited[i-1][j-1]) e = dfs(matrix,visited,n,m,i-1,j-1);
    if (i>0 && j+1<n && matrix[i-1][j+1]==1 && !visited[i-1][j+1]) f = dfs(matrix,visited,n,m,i-1,j+1);
    if (i+1<m && j>0 && matrix[i+1][j-1]==1 && !visited[i+1][j-1]) g = dfs(matrix,visited,n,m,i+1,j-1);
    if (i+1<m && j+1<n && matrix[i+1][j+1]==1 && !visited[i+1][j+1]) h = dfs(matrix,visited,n,m,i+1,j+1);

    return a+b+c+d+e+f+g+h+1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> matrix(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
