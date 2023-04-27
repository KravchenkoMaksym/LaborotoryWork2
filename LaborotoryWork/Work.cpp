#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main() {
    int choice;
    do {
        cout << "Please choose an option:\n";
        cout << "1. Task 1\n";
        cout << "2. Task 2\n";
        cout << "3. Exit\n";
        cin >> choice;

        switch (choice) {
        /*���������� ������ � ������������� �������� ��������.
          ������ ��� ����� a, b, c �� d. ��������� ����� ��� ������������ �������� �������� ��
          ������(�������� �� �� �������� �����).*/
        case 1: {
            int a, b, c, d;

            cout << "Enter the values of a, b, c, and d: ";
            cin >> a >> b >> c >> d;

            int temp1 = (a << 4) + (a << 0);   // 17 * a
            int temp2 = (c << 8) + (c << 4);   // 312 * c
            int temp3 = temp1 + temp2;         // 17 * a + 312 * c
            int temp4 = b << 7;                // b * 120
            int temp5 = d << 7;                // d * 127
            int result = (temp3 >> 5) - temp4 + temp5;  // (17 * a + 312 * c) / 32 - b * 120 + d * 127

            cout << "Result: " << result << endl;

            break;
        }
           /*������ ����� �� 128 �������. ��������� �������� �� 128 �������. 
           ��������� ������ ����� �����, ��� ������ ������ ������ ����������� � ��� �����. 
           ��� ����� ����� ���� ���������:
                � ���� 0-6 ������� ������� � ����� (7 ���),
                � ���� 7-14 ASCII - ��� ����� (8 ��),
                15 �� � �� ������� ������ ���� ���� (1 ��) */
        case 2: {
            string text;
            cout << "Enter up to 128 characters: ";
            cin.ignore();
            getline(cin, text);

            // ���������� ����� �������� �� 128 �������
            text.resize(128, ' ');

            // ������� ����� � ����������� ������
            for (char c : text) {
                bitset<16> b;
                b.set(0, c & 1);
                b.set(1, (c >> 1) & 1);
                b.set(2, (c >> 2) & 1);
                b.set(3, (c >> 3) & 1);
                b.set(4, (c >> 4) & 1);
                b.set(5, (c >> 5) & 1);
                b.set(6, (c >> 6) & 1);
                b.set(7, (int)c >> 8);
                b.set(15, b.count() % 2 == 0);
                cout << b.to_ulong() << " ";
            }
            cout << endl;
            break;
        }
        case 3: {
            cout << "Exiting program...\n";
            break;
        }
        default:
            cout << "Invalid choice, please try again.\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
