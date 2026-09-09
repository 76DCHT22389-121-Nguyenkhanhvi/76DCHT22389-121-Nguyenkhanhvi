#include <iostream>
#include <cmath>

using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Hàm tạo không đối
    PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }

    // Hàm tạo có đối
    PhanSo(int tu, int mau) {
        tuSo = tu;
        mauSo = (mau != 0) ? mau : 1;
    }

    // Hàm hủy
    ~PhanSo() {}

    // Hàm tìm UCLN
    int UCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return (a != 0) ? a : 1;
    }

    // Phương thức rút gọn
    void rutGon() {
        int uc = UCLN(tuSo, mauSo);
        tuSo /= uc;
        mauSo /= uc;
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // Nạp chồng toán tử nhập (>>)
    friend istream& operator >> (istream &in, PhanSo &p) {
        cout << "Nhap tu so: ";
        in >> p.tuSo;
        do {
            cout << "Nhap mau so (khac 0): ";
            in >> p.mauSo;
            if (p.mauSo == 0) {
                cout << "Mau so phai khac 0. Nhap lại!\n";
            }
        } while (p.mauSo == 0);
        return in;
    }

    // Nạp chồng toán tử xuất (<<)
    friend ostream& operator << (ostream &out, const PhanSo &p) {
        if (p.mauSo == 1) {
            out << p.tuSo;
        } else if (p.tuSo == 0) {
            out << 0;
        } else {
            out << p.tuSo << "/" << p.mauSo;
        }
        return out;
    }

    // Nạp chồng toán tử cộng (+)
    PhanSo operator + (const PhanSo &p) {
        PhanSo kq;
        kq.tuSo = this->tuSo * p.mauSo + this->mauSo * p.tuSo;
        kq.mauSo = this->mauSo * p.mauSo;
        kq.rutGon();
        return kq;
    }

    // Nạp chồng toán tử trừ (-)
    PhanSo operator - (const PhanSo &p) {
        PhanSo kq;
        kq.tuSo = this->tuSo * p.mauSo - this->mauSo * p.tuSo;
        kq.mauSo = this->mauSo * p.mauSo;
        kq.rutGon();
        return kq;
    }

    // Nạp chồng toán tử nhân (*)
    PhanSo operator * (const PhanSo &p) {
        PhanSo kq;
        kq.tuSo = this->tuSo * p.tuSo;
        kq.mauSo = this->mauSo * p.mauSo;
        kq.rutGon();
        return kq;
    }

    // Nạp chồng toán tử chia (/)
    PhanSo operator / (const PhanSo &p) {
        PhanSo kq;
        kq.tuSo = this->tuSo * p.mauSo;
        kq.mauSo = this->mauSo * p.tuSo;
        kq.rutGon();
        return kq;
    }
};

int main() {
    PhanSo p1, p2;
    
    cout << "--- Nhap phan so thu nhat ---\n";
    cin >> p1;
    cout << "--- Nhap phan so thu hai ---\n";
    cin >> p2;

    cout << "\nPhan so 1: " << p1 << endl;
    cout << "Phan so 2: " << p2 << endl;

    cout << "\n--- KET QUA TINH TOAN (Da toi gian) ---" << endl;
    cout << p1 << " + " << p2 << " = " << (p1 + p2) << endl;
    cout << p1 << " - " << p2 << " = " << (p1 - p2) << endl;
    cout << p1 << " * " << p2 << " = " << (p1 * p2) << endl;
    cout << p1 << " / " << p2 << " = " << (p1 / p2) << endl;

    return 0;
}
