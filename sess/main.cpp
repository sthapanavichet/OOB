#include <iostream>
#include <string>
#include <cwctype>
int main() {
    using namespace std;
    string s = "G fmnc wms bgbl’r rpylqdcp gr zw fylb. Rfyr'q ufyr amknsrcpq ypc dmp. Bmgle gr zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. Sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. Lmu ynnjw rfc yjempgrfk ml rfc spj.";
    for(int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
        if(isalpha(s[i])) {
            s[i] += 2;
            if ((s[i] > 'z' && s[i] <= 'z' + 2) || (s[i] > 'Z' && s[i] <= 'Z' + 2)) {
                s[i] -= 26; // Wrap around to 'a' or 'A'
            }
        }
    }
    cout << s << endl;
}
