#include<iostream>

using namespace std;

/*
 * Rule
 * ���ڴ� 1~100 ���̿� ������ �ȴ�.
 * �� ���α׷���, ������� ���ڰ� ������������ ��µȴٴ� ���� �������� �Ѵ�.
 * �� ������ �ڸ����� 1, 2, 3.
 * ���⼭ Ư�� 3�ڸ� ���� ������ ���ڴ� 100 �ϳ��ۿ� �����Ƿ�, ������ 100�� �ִ��� �������� üũ�Ѵ�.
 * �׸��� ���� �Է��� String ���� �޾� ���̸� ���Ѵ�.
 *
 */
int main(){
    int n = 0, current_value = 0,string_length = 0,sum=0, i;
    string number_string = "", temp = "";
    cin >> n;
    cin >> number_string;
    string_length = (int)number_string.length();
    //100�� �ִ��� �������� üũ
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
            cout << "1�ڸ� ���� ��� : " << current_value <<  " string length : " <<  string_length << " / n : " << n << endl;
        }
    }
    for (int j = i; j < number_string.length(); j += 2) {
        current_value = (number_string[j] - '0')*10 + (number_string[j+1] - '0');
        cout << "2�ڸ� ���� ��� : " << current_value <<  endl;
        sum += current_value;
    }
    cout << "string_length : " <<string_length<< "/ n: " <<n << " / sum : " << sum;
    cin >> sum;
    return 0;
}