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
        mauSo = (mau != 0) ? mau : 1; // Tránh mẫu số bằng 0
    }

    // Hàm hủy
    ~PhanSo() {
        // Hủy đối tượng
    }

    // Hàm tìm ước chung lớn nhất (UCLN) phục vụ rút gọn
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

    // Phương thức rút gọn phân số
    void rutGon() {
        int uc = UCLN(tuSo, mauSo);
        tuSo /= uc;
        mauSo /= uc;
        // Đưa dấu âm lên tử số
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // Phương thức nhập
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mauSo;
            if (mauSo == 0) {
                cout << "Mau so phai khac 0. Vui long nhap lai!\n";
            }
        } while (mauSo == 0);
    }

    // Phương thức xuất
    void xuat() {
        if (mauSo == 1) {
            cout << tuSo << endl;
        } else if (tuSo == 0) {
            cout << 0 << endl;
        } else {
            cout << tuSo << "/" << mauSo << endl;
        }
    }

    // Các phương thức tính toán (trả về phân số mới đã rút gọn)
    PhanSo cong(PhanSo p) {
        PhphanSo: // Nhãn giả lập, dùng biến kết quả chuẩn
        PhanSo kq;
        kq.tuSo = this->tuSo * p.mauSo + this->mauSo * p.tuSo;
        kq.mauSo = this->mauSo * p.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo tru(PhanSo p) {
        PhanSo kq;
        kq.tuSo = this->tuSo * p.mauSo - this->mauSo * p.tuSo;
        kq.mauSo = this->mauSo * p.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo nhan(PhanSo p) {
        PhanSo kq;
        kq.tuSo = this->tuSo * p.tuSo;
        kq.mauSo = this->mauSo * p.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo chia(PhanSo p) {
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
    p1.nhap();
    cout << "--- Nhap phan so thu hai ---\n";
    p2.nhap();

    cout << "\nPhan so 1: "; p1.xuat();
    cout << "Phan so 2: "; p2.xuat();

    cout << "\n--- KET QUA TINH TOAN ---" << endl;
    phTong = p1.cong(p2); // Sửa tên biến hiển thị
    cout << "Cong: "; p1.cong(p2).xuat();
    cout << "Tru: "; p1.tru(p2).xuat();
    cout << "Nhan: "; p1.nhan(p2).xuat();
    cout << "Chia: "; p1.chia(p2).xuat();

    return 0;
}
