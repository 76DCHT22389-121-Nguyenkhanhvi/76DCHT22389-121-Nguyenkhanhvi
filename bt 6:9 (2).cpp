#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Câu 1: Khai báo lớp sinh viên với các thuộc tính: họ tên, năm sinh, điểm 4 môn học.
class SinhVienBai7 {
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:
    // Câu 2: Phương thức nhập, xuất, tính điểm trung bình
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        for (int i = 0; i < 4; i++) {
            cout << "Nhap diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    void xuat() {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh << " | DTB: " << tinhDTB() << endl;
    }

    float tinhDTB() {
        float tong = 0;
        for (int i = 0; i < 4; i++) tong += diem[i];
        return tong / 4;
    }

    // Phương thức bổ trợ cho Câu 3: Kiểm tra tiêu chuẩn thi tốt nghiệp (ĐTB < 7, không môn nào < 5)
    bool datTieuChuanThiTotNghiep() {
        if (tinhDTB() >= 7.0) return false;
        for (int i = 0; i < 4; i++) {
            if (diem[i] < 5.0) return false;
        }
        return true;
    }
};

int main() {
    // Câu 3: Nhập n sinh viên. In thông tin sinh viên phải thi tốt nghiệp.
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    vector<SinhVienBai7> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "\n--- Sinh vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }

    cout << "\n=== DANH SACH SINH VIEN PHAI THI TOT NGHIEP ===\n";
    bool coSV = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].datTieuChuanThiTotNghiep()) {
            ds[i].xuat();
            coSV = true;
        }
    }
    if (!coSV) cout << "Khong co sinh vien nao dap ung tieu chi thi tot nghiep.\n";

    return 0;
}
