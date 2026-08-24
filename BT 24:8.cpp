#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Thư viện hỗ trợ định dạng in theo cột

using namespace std;

// Tạo LỚP Nhân Viên thay vì struct
class NhanVien {
private:
    string ten;
    int tuoi;

public:
    // 1. Constructor không đối (Mặc định)
    NhanVien() {
        ten = "Chua cap nhat";
        tuoi = 0;
    }

    // 2. Constructor có đối
    NhanVien(string t, int tu) {
        ten = t;
        tuoi = tu;
    }

    // Các hàm Getter để lấy dữ liệu in ra màn hình
    string getTen() const { return ten; }
    int getTuoi() const { return tuoi; }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien (n): ";
    cin >> n;

    // Sử dụng CÁCH 3 (Vector)
    vector<NhanVien> ds;

    // Nhập dữ liệu
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
        string tempTen;
        int tempTuoi;

        // Nhập vào các biến tạm
        cout << "Nhap ten: ";
        cin.ignore(); // Xóa bộ nhớ đệm
        getline(cin, tempTen);
        
        cout << "Nhap tuoi: ";
        cin >> tempTuoi;

        // 3. Sử dụng Constructor CÓ ĐỐI để khởi tạo và đưa vào mảng
        NhanVien nv(tempTen, tempTuoi);
        ds.push_back(nv);
    }

    // 4. Xuất dữ liệu nhân viên THEO CỘT
    cout << "\n\n================ DANH SACH NHAN VIEN ================" << endl;
    
    // In tiêu đề cột (Sử dụng setw để căn lề, left để căn trái)
    cout << left << setw(10) << "STT"
         << left << setw(25) << "Ho va Ten"
         << left << setw(10) << "Tuoi" << endl;
         
    // In đường kẻ ngang
    cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;

    // In dữ liệu từng nhân viên
    for (int i = 0; i < ds.size(); i++) {
        cout << left << setw(10) << i + 1
             << left << setw(25) << ds[i].getTen()
             << left << setw(10) << ds[i].getTuoi() << endl;
    }

    return 0;
}
