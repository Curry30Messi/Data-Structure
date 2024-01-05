#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

bool cmp(Element &a, Element &b) {

    return a.col < b.col;
}

void swap( Element &a, Element &b)
{
	struct Element temp;
	temp.row = a.row;
	temp.col = a.col;
	temp.value = a.value; 
    a.row=b.row;
    a.col=b.col;
    a.value=b.value;
    b.row=temp.row;
	b.col=temp.col;
	b.value=temp.value;
}
int main() {
    int rows, cols, num_elements;
    cin >> rows >> cols >> num_elements;
    
    vector<Element> sparse_matrix;
    
    for (int i = 0; i < num_elements; i++) {
        Element element;
        cin >> element.row >> element.col >> element.value;
        sparse_matrix.push_back(element);
    }
    
	for (int i = 0; i < num_elements - 1; i++)
		for (int j = 0; j < num_elements - i - 1; j++)
			if (sparse_matrix[j].col > sparse_matrix[j + 1].col)
				swap(sparse_matrix[j], sparse_matrix[j + 1]);


    cout << cols << " " << rows << " " << num_elements <<endl;
    for (Element element : sparse_matrix) {
       cout << element.col << " " << element.row << " " << element.value << endl;
    }
    
    return 0;
}
