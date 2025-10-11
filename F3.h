#ifndef F3_h
#define F3_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Thong tin chuyen bay
struct Flight {
    string maChuyenBay;
    string noiDi;
    string noiDen;
    string ngayBay;
    string gioBay;
    int tongSoGhe;
    int gheTrong;

    void hienThiThongTin() const;
};

// Thong tin hanh khach
struct Passenger {
    string maHK;
    string hoTen;
    string cmnd;
    string sdt;

    void nhapThongTin();
    void hienThi() const;
};

// Thong tin ve
struct Ticket {
    string maVe;
    string maChuyenBay;
    string maHK;
    string loaiVe;  // Thuong, Pho thong, Hang nang cap
};

// He thong quan ly chuyen bay
class AirlineSystem {
private:
    vector<Flight> dsChuyenBay;
    vector<Passenger> dsHanhKhach;
    vector<Ticket> dsVe;

public:
    void hienThiChuyenBayConCho();
    void datVe();
    void themChuyenBay(const Flight& f);
    void themHanhKhach(const Passenger& p);
    void hienThiTatCaVe() const;
    size_t soLuongHanhKhach() const { return dsHanhKhach.size(); }
};

void menuDatVe(); 

#endif

