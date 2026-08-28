#include <iostream>
using namespace std;

// Câu 1: Khai báo lớp ma trận
class MaTran {
private:
    int soHang;
    int soCot;
    int phanTu[100][100]; // Sử dụng mảng 2 chiều tĩnh với kích thước tối đa 100x100

public:
    // Hàm tạo (Constructor) khởi tạo ma trận rỗng
    MaTran() {
        soHang = 0;
        soCot = 0;
    }

    // Các hàm getter để lấy giá trị số hàng và số cột từ bên ngoài lớp
    int getSoHang() {
        return soHang;
    }
    
    int getSoCot() {
        return soCot;
    }

    // Câu 2: Phương thức nhập đối tượng ma trận
    void nhap() {
        cout << "Nhap so hang: ";
        cin >> soHang;
        cout << "Nhap so cot: ";
        cin >> soCot;
        cout << "Nhap cac phan tu cua ma tran:" << endl;
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << "a[" << i << "][" << j << "] = ";
                cin >> phanTu[i][j];
            }
        }
    }

    // Câu 2: Phương thức xuất đối tượng ma trận
    void xuat() {
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << phanTu[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Khai báo hàm bạn để cộng hai ma trận
    friend MaTran congMaTran(MaTran mt1, MaTran mt2);
};

// Câu 3: Cài đặt hàm bạn cộng hai ma trận đồng cấp
MaTran congMaTran(MaTran mt1, MaTran mt2) {
    MaTran ketQua;
    
    // Kiểm tra điều kiện đồng cấp
    if (mt1.soHang != mt2.soHang || mt1.soCot != mt2.soCot) {
        cout << "Loi: Hai ma tran khong dong cap, khong the cong!" << endl;
        return ketQua;
    }

    ketQua.soHang = mt1.soHang;
    ketQua.soCot = mt1.soCot;

    // Thực hiện phép cộng các phần tử tương ứng
    for (int i = 0; i < mt1.soHang; i++) {
        for (int j = 0; j < mt1.soCot; j++) {
            ketQua.phanTu[i][j] = mt1.phanTu[i][j] + mt2.phanTu[i][j];
        }
    }
    return ketQua;
}

int main() {
    MaTran mt1, mt2, mtTong;

    cout << "--- Nhap Ma Tran 1 ---" << endl;
    mt1.nhap();

    cout << "\n--- Nhap Ma Tran 2 (Can dong cap voi ma tran 1) ---" << endl;
    mt2.nhap();

    // Câu 3: In ra màn hình hai ma trận ban đầu
    cout << "\n=== MA TRAN 1 BAN DAU ===" << endl;
    mt1.xuat();

    cout << "\n=== MA TRAN 2 BAN DAU ===" << endl;
    mt2.xuat();

    // Thực hiện cộng và in ra ma trận kết quả
    mtTong = congMaTran(mt1, mt2);
    
    // Sử dụng hàm getter thay vì truy cập trực tiếp biến private
    if (mtTong.getSoHang() > 0 && mtTong.getSoCot() > 0) {
        cout << "\n=== MA TRAN KET QUA (TONG) ===" << endl;
        mtTong.xuat();
    }

    return 0;
}
