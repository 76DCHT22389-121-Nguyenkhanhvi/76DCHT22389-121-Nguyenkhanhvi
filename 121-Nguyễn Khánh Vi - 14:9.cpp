#include <iostream>
#include <string>

using namespace std;

// ==================== CÂU 1 ====================
// Khai báo lớp Nguoi (Lớp cha)
class Nguoi {
protected:
    string hoTen;
    int namSinh;

public:
    // ==================== CÂU 2 ====================
    // Hàm tạo không đối số
    Nguoi() {
        hoTen = "";
        namSinh = 0;
    }

    // Hàm tạo có đối số
    Nguoi(string _hoTen, int _namSinh) {
        hoTen = _hoTen;
        namSinh = _namSinh;
    }

    // Phương thức nhập
    virtual void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore(); // Xóa bộ nhớ đệm trước khi dùng getline
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
    }

    // Phương thức xuất
    virtual void xuat() {
        cout << "Ho ten: " << hoTen << ", Nam sinh: " << namSinh;
    }
};

// Khai báo lớp SinhVien kế thừa từ lớp Nguoi (Lớp con)
class SinhVien : public Nguoi {
private:
    string maSV;
    float diemTB;

public:
    // ==================== CÂU 2 ====================
    // Hàm tạo không đối số (Gọi hàm tạo không đối của lớp cha)
    SinhVien() : Nguoi() {
        maSV = "";
        diemTB = 0.0;
    }

    // Hàm tạo có đối số (Gọi hàm tạo có đối của lớp cha)
    SinhVien(string _hoTen, int _namSinh, string _maSV, float _diemTB) : Nguoi(_hoTen, _namSinh) {
        maSV = _maSV;
        diemTB = _diemTB;
    }

    // Phương thức nhập (Ghi đè - Override)
    void nhap() override {
        Nguoi::nhap(); // Gọi hàm nhập của lớp cha
        cout << "Nhap ma sinh vien: ";
        cin.ignore();
        getline(cin, maSV);
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
    }

    // Phương thức xuất (Ghi đè - Override)
    void xuat() override {
        Nguoi::xuat(); // Gọi hàm xuất của lớp cha
        cout << ", Ma SV: " << maSV << ", Diem TB: " << diemTB << endl;
    }

    // Hàm lấy giá trị điểm trung bình để phục vụ cho việc sắp xếp
    float getDiemTB() {
        return diemTB;
    }
};

// ==================== CÂU 3 ====================
// Hàm sắp xếp danh sách sinh viên giảm dần theo điểm trung bình
void sapXepGiamDan(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getDiemTB() < ds[j].getDiemTB()) {
                // Hoán vị 2 đối tượng
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

int main() {
    // --- Chạy thử hàm tạo có đối (Yêu cầu của Câu 2) ---
    cout << "--- TEST HAM TAO CO DOI ---" << endl;
    SinhVien svTest("Nguyen Khanh Vi", 2005, "SV001", 9.5);
    svTest.xuat();
    cout << "---------------------------" << endl;

    // --- Thực hiện Câu 3: Nhập n sinh viên, sắp xếp và in ra ---
    int n;
    cout << "\nNhap so luong sinh vien n = ";
    cin >> n;

    // Cấp phát mảng động chứa n sinh viên
    SinhVien* ds = new SinhVien[n];

    // Nhập danh sách
    cout << "\n--- NHAP DANH SACH SINH VIEN ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        ds[i].nhap();
    }

    // Sắp xếp
    sapXepGiamDan(ds, n);

    // In danh sách
    cout << "\n--- DANH SACH SINH VIEN GIAM DAN THEO DIEM TB ---" << endl;
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }

    // Giải phóng bộ nhớ
    delete[] ds;

    return 0;
}
