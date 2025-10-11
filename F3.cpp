// Đặt vé cho hành khách
// - Hiển thị các chuyến bay còn chỗ trống.
// - Yêu cầu nhập mã chuyến bay muốn đặt.
// - Yêu cầu nhập thông tin hành khách (hoặc chọn từ danh sách đã có).
// - Xác nhận đặt vé, lưu thông tin vé (mã vé, thông tin chuyến bay, thông tin hành khách).
// - Cập nhật lại số ghế trống của chuyến bay.
// - Loại vé đặt
#include "F3.h"
#include <iomanip>
#include <iostream>

using namespace std;

// thong tin chuyen bay
void Flight::hienThiThongTin() const {
    cout << left << setw(10) << maChuyenBay
         << setw(15) << noiDi
         << setw(15) << noiDen
         << setw(12) << ngayBay
         << setw(8) << gioBay
         << "Ghe trong: " << gheTrong << "/" << tongSoGhe << endl;
}
// thong tin hanh khach
void Passenger::nhapThongTin() {
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap CMND/CCCD: "; getline(cin, cmnd);
    cout << "Nhap so dien thoai: "; getline(cin, sdt);
}

void Passenger::hienThi() const {
    cout << "Ma HK: " << maHK
         << " | Ho ten: " << hoTen
         << " | CMND: " << cmnd
         << " | SDT: " << sdt << endl;
}

// he thong quan ly chuyen bay
void AirlineSystem::themChuyenBay(const Flight& f) {
    dsChuyenBay.push_back(f);
}

void AirlineSystem::themHanhKhach(const Passenger& p) {
    dsHanhKhach.push_back(p);
}

void AirlineSystem::hienThiChuyenBayConCho() {
    cout << "\n===== DANH SACH CHUYEN BAY CON CHO =====\n";
    if (dsChuyenBay.empty()) {
        cout << "Chua co chuyen bay nao!\n";
        return;
    }

    bool co = false;
    for (const auto &cb : dsChuyenBay) {
        if (cb.gheTrong > 0) {
            cb.hienThiThongTin();
            co = true;
        }
    }
    if (!co) cout << "Tat ca cac chuyen bay da het cho!\n";
}

void AirlineSystem::hienThiTatCaVe() const {
    cout << "\n===== DANH SACH VE =====\n";
    if (dsVe.empty()) {
        cout << "Chua co ve nao!\n";
        return;
    }

    for (const auto &ve : dsVe) {
        cout << "Ma ve: " << ve.maVe
             << " | Ma chuyen bay: " << ve.maChuyenBay
             << " | Ma HK: " << ve.maHK
             << " | Loai ve: " << ve.loaiVe << endl;
    }
}

void AirlineSystem::datVe() {
    if (dsChuyenBay.empty()) {
        cout << "⚠️  Chua co chuyen bay nao!\n";
        return;
    }

    hienThiChuyenBayConCho();

    cout << "\nNhap ma chuyen bay muon dat: ";
    string maCB;
    getline(cin, maCB);

    Flight* cb = nullptr;
    for (auto &f : dsChuyenBay) {
        if (f.maChuyenBay == maCB) {
            cb = &f;
            break;
        }
    }
    if (!cb) {
        cout << "❌ Khong tim thay chuyen bay!\n";
        return;
    }
    if (cb->gheTrong <= 0) {
        cout << "❌ Chuyen bay da het cho!\n";
        return;
    }

    Passenger hk;
    cout << "\n--- Nhap thong tin hanh khach ---\n";
    hk.nhapThongTin();
    hk.maHK = "HK" + to_string(dsHanhKhach.size() + 1);
    dsHanhKhach.push_back(hk);

    Ticket ve;
    ve.maVe = "VE" + to_string(dsVe.size() + 1);
    ve.maChuyenBay = cb->maChuyenBay;
    ve.maHK = hk.maHK;

    cout << "Nhap loai ve (Economy/Business/First): ";
    getline(cin, ve.loaiVe);

    cout << "\nXac nhan dat ve? (y/n): ";
    char x; cin >> x; cin.ignore();

    if (x == 'y' || x == 'Y') {
        dsVe.push_back(ve);
        cb->gheTrong--;
        cout << "✅ Dat ve thanh cong! Ma ve: " << ve.maVe << endl;
    } else {
        cout << "❌ Huy dat ve.\n";
    }
}

// menu dat ve
static AirlineSystem sys;

void menuDatVe() {
    int chon;
    do {
        cout << "\n===== HE THONG DAT VE MAY BAY =====\n";
        cout << "1. Them chuyen bay\n";
        cout << "2. Xem danh sach chuyen bay con cho\n";
        cout << "3. Dat ve\n";
        cout << "4. Xem danh sach ve da dat\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "Lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1: {
                Flight f;
                cout << "Nhap ma chuyen bay: "; getline(cin, f.maChuyenBay);
                cout << "Noi di: "; getline(cin, f.noiDi);
                cout << "Noi den: "; getline(cin, f.noiDen);
                cout << "Ngay bay (dd/mm/yyyy): "; getline(cin, f.ngayBay);
                cout << "Gio bay (hh:mm): "; getline(cin, f.gioBay);
                cout << "Tong so ghe: "; cin >> f.tongSoGhe; cin.ignore();
                f.gheTrong = f.tongSoGhe;
                sys.themChuyenBay(f);
                cout << "Da them chuyen bay moi!\n";
                break;
            }
            case 2:
                sys.hienThiChuyenBayConCho();
                break;
            case 3:
                sys.datVe();
                break;
            case 4:
                sys.hienThiTatCaVe();
                break;
            case 0:
                cout << "Tro ve menu chinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 0);
}
