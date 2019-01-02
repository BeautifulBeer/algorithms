#include<iostream>

using namespace std;

/*
 * Rule
 * 숫자는 1~100 사이에 나오게 된다.
 * 이 프로그램은, 공백없는 숫자가 오름차순으로 출력된다는 것을 가정으로 한다.
 * 총 숫자의 자릿수는 1, 2, 3.
 * 여기서 특히 3자리 수를 가지는 숫자는 100 하나밖에 없으므로, 사전에 100이 있는지 없는지를 체크한다.
 * 그리고 숫자 입력을 String 으로 받아 길이를 구한다.
 *
 */
int main(){
    int n = 0, current_value = 0,string_length = 0,sum=0, i;
    string number_string = "", temp = "";
    cin >> n;
    cin >> number_string;
    string_length = (int)number_string.length();
    //100이 있는지 없는지를 체크
    if(string_length >= 3) {
        while(1) {
            string temp = number_string.substr(number_string.find_last_of("1"));
            if (temp == "100") {

                number_string.resize(number_string.size() - 3);
                sum += 100;
                string_length -= 3;
                n--;
            }else{
                break;
            }
        }
    }
    for (i = 0; i < number_string.length(); i++) {
        if (n == (string_length)/2) {
            break;
        }else {
            current_value = number_string[i] - '0';
            sum += current_value;
            string_length--;
            n--;
            cout << "1자리 수일 경우 : " << current_value <<  " string length : " <<  string_length << " / n : " << n << endl;
        }
    }
    for (int j = i; j < number_string.length(); j += 2) {
        current_value = (number_string[j] - '0')*10 + (number_string[j+1] - '0');
        cout << "2자리 수일 경우 : " << current_value <<  endl;
        sum += current_value;
    }
    cout << "string_length : " <<string_length<< "/ n: " <<n << " / sum : " << sum;
    cin >> sum;
    return 0;
}