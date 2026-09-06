#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Câu 1: Khai báo lớp sinh viên với các thuộc tính: họ tên, năm sinh, điểm 5 môn.
class SinhVienBai6 {
private:
    string hoTen;
    int namSinh;
    float diem[5];
    string tenMon[5] = {"Mon 1", "Mon 2", "Mon 3", "Mon 4", "Mon 5"};

public:
    // Câu 2: Phương thức nhập, xuất, tính điểm trung bình
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        for (int i = 0; i < 5; i++) {
            cout << "Nhap diem " << tenMon[i] << ": ";
            cin >> diem[i];
        }
    }

    void xuat() {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh << " | DTB: " << tinhDTB() << endl;
    }

    float tinhDTB() {
        float tong = 0;
        for (int i = 0; i < 5; i++) tong += diem[i];
        return tong / 5;
    }

    // Phương thức bổ trợ cho Câu 3: In các môn phải thi lại (< 5 điểm)
    void inThongTinThiLai() {
        bool phaiThiLai = false;
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5.0) {
                if (!phaiThiLai) {
                    cout << "- Sinh vien " << hoTen << " thi lai cac mon:\n";
                    phaiThiLai = true;
                }
                cout << "  + " << tenMon[i] << ": " << diem[i] << " diem\n";
            }
        }
    }
};

int main() {
    // Câu 3: Nhập n sinh viên. In ra sinh viên phải thi lại, tên môn và điểm thi lại.
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    vector<SinhVienBai6> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "\n--- Sinh vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }

    cout << "\n=== THONG TIN THI LAI ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].inThongTinThiLai();
    }
    return 0;
}
