#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Câu 1: Khai báo lớp người
class Nguoi {
protected:
    string hoTen;
    int namSinh;

public:
    // Câu 2: Phương thức nhập, xuất cho lớp người
    virtual void nhap() {
        cout << "Nhap ho ten: ";
        // Sử dụng cin >> ws để loại bỏ ký tự khoảng trắng thừa/dấu enter còn sót lại
        getline(cin >> ws, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
    }

    virtual void xuat() const {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh;
    }

    string getHoTen() const {
        return hoTen;
    }
};

// Câu 1: Khai báo lớp sinh viên kế thừa từ lớp người
class SinhVien : public Nguoi {
private:
    string maSV;
    float diemTB;

public:
    // Câu 2: Phương thức nhập, xuất cho lớp sinh viên
    void nhap() override {
        Nguoi::nhap(); // Gọi phương thức nhập của lớp cha
        cout << "Nhap ma sinh vien: ";
        getline(cin >> ws, maSV);
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
    }

    void xuat() const override {
        Nguoi::xuat(); // Gọi phương thức xuất của lớp cha
        cout << " | Ma SV: " << maSV << " | Diem TB: " << diemTB << endl;
    }

    string getMaSV() const {
        return maSV;
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    // Sử dụng vector để lưu trữ danh sách n sinh viên
    vector<SinhVien> danhSach(n);

    // Câu 3: Nhập vào n sinh viên
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin sinh vien thu " << i + 1 << " ---" << endl;
        danhSach[i].nhap();
    }

    // Câu 3: Nhập thông tin tìm kiếm
    string tuKhoa;
    cout << "\nNhap ma sinh vien hoac ho ten can tim: ";
    getline(cin >> ws, tuKhoa);

    bool timThay = false;
    cout << "\n--- Ket qua tim kiem ---" << endl;
    
    // Tìm kiếm và in ra màn hình
    for (int i = 0; i < n; i++) {
        if (danhSach[i].getMaSV() == tuKhoa || danhSach[i].getHoTen() == tuKhoa) {
            danhSach[i].xuat();
            timThay = true;
        }
    }

    // Thông báo nếu không tìm thấy
    if (!timThay) {
        cout << "Khong tim thay sinh vien mang ten hoac ma nay!" << endl;
    }

    return 0;
}
