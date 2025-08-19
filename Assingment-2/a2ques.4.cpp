// // 4(a)

// #include <iostream>
// using namespace std;

// int main() {
//     char str1[100], str2[100];
//     cout << "Enter first string: ";
//     cin.getline(str1, 100);

//     cout << "Enter second string: ";
//     cin.getline(str2, 100);

//     int i = 0;
//     while (str1[i] != '\0') {
//         i++;
//     }
//     int j = 0;
//     while (str2[j] != '\0') {
//         str1[i] = str2[j];
//         i++;
//         j++;
//     }

//     str1[i] = '\0';

//     cout << "Concatenated string: " << str1 << endl;

//     return 0;
// }


// 4(b)

// #include <iostream>
// using namespace std;

// int main() {
//     char str[100];
//     cout << "Enter a string: ";
//     cin.getline(str, 100);

//     int length = 0;
//     while (str[length] != '\0') {
//         length++;
//     }

//     int start = 0, end = length - 1;

//     for(int i=start, j=end;i<=j;i++,j--) {
//         char temp = str[i];
//         str[i] = str[j];
//         str[j] = temp;
//     }

//     cout << "Reversed string: " << str << endl;

//     return 0;
// }


// 4(c)

// #include <iostream>
// using namespace std;

// int main() {
//     char str[100];
//     cout << "Enter a string: ";
//     cin.getline(str, 100);

//     int i = 0, j = 0;
//     while (str[i] != '\0') {
//         if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' &&
//             str[i] != 'o' && str[i] != 'u' &&
//             str[i] != 'A' && str[i] != 'E' && str[i] != 'I' &&
//             str[i] != 'O' && str[i] != 'U') {
//             str[j] = str[i];
//             j++;
//         }
//         i++;
//     }
//     str[j] = '\0';  

//     cout << str << endl;

//     return 0;
// }


// 4(d)

// #include <iostream>
// using namespace std;

// int main() {
//     char str[100];
//     cout << "Enter a string: ";
//     cin.getline(str, 100);
//     int len=0;
//     int i=0;
//     while(str[i]!='\0'){
//         len++;
//         i++;
//     }

    
//     for(int i=0;i<=len-2;i++){
//         for(int j=0;j<=len-2-i;j++){
//             if((int)str[j]>(int)str[j+1]){
//                 int temp=str[j];
//                 str[j]=str[j+1];
//                 str[j+1]=temp;
//             }
//         }
//     }
//     cout<<str;
//     }


// 4(e)


