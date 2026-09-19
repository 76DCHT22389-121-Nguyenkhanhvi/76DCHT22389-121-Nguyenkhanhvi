#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Câu 1: Khai báo lớp môn học
class MonHoc {
protected:
    string tenMonHoc;
    float diemCC; // Điểm chuyên cần
    float diemKT; // Điểm kiểm tra
    float diemDT; // Điểm thi

public:
    // Câu 2: Xây dựng phương thức nhập cho môn học
    virtual void nhap() {
        cout << "Nhap ten mon hoc: ";
        getline(cin >> ws, tenMonHoc);
        cout << "Nhap diem chuyen can (CC): ";
        cin >> diemCC;
        cout << "Nhap diem kiem tra (KT): ";
        cin >> diemKT;
        cout << "Nhap diem thi (DT): ";
        cin >> diemDT;
    }

    // Câu 2: Xây dựng phương thức xuất cho môn học
    virtual void xuat() const {
        cout << "Mon hoc: " << tenMonHoc
             << " | CC: " << diemCC
             << " | KT: " << diemKT
             << " | DT: " << diemDT;
    }
};

// Câu 1: Khai báo lớp sinh viên kế thừa từ lớp môn học
class SinhVien : public MonHoc {
private:
    string hoTen;
    string lop;
    string maSV;

public:
    // Câu 2: Phương thức nhập (ghi đè và gọi lại phương thức của lớp cha)
    void nhap() override {
        cout << "Nhap ho ten sinh vien: ";
        getline(cin >> ws, hoTen);
        cout << "Nhap ma sinh vien: ";
        getline(cin >> ws, maSV);
        cout << "Nhap lop: ";
        getline(cin >> ws, lop);
        
        MonHoc::nhap(); // Nhập thông tin điểm và môn học
    }

    // Câu 2: Phương thức tính điểm học phần
    float tinhDiemHocPhan() const {
        // Tạm tính theo công thức: 10% chuyên cần + 30% kiểm tra + 60% thi
        return (diemCC * 0.1f) + (diemKT * 0.3f) + (diemDT * 0.6f);
    }

    // Câu 2: Phương thức xuất
    void xuat() const override {
        cout << "SV: " << hoTen << " - Ma: " << maSV << " - Lop: " << lop << endl;
        MonHoc::xuat();
        cout << " | Diem Hoc Phan: " << tinhDiemHocPhan() << endl;
    }

    // Kiểm tra điều kiện cấm thi cho Câu 3
    bool biCamThi() const {
        // Cấm thi nếu điểm chuyên cần dưới 5 hoặc điểm kiểm tra bằng 0
        return (diemCC < 5 || diemKT == 0);
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

    cout << "\n=============================================" << endl;
    cout << "   DANH SACH SINH VIEN BI CAM THI   " << endl;
    cout << "=============================================" << endl;
    
    bool coNguoiCamThi = false;
    
    // Câu 3: In ra màn hình thông tin các sinh viên bị cấm thi
    for (int i = 0; i < n; i++) {
        if (danhSach[i].biCamThi()) {
            danhSach[i].xuat();
            cout << "---------------------------------------------" << endl;
            coNguoiCamThi = true;
        }
    }

    if (!coNguoiCamThi) {
        cout << "Khong co sinh vien nao bi cam thi." << endl;
    }

    return 0;
}
