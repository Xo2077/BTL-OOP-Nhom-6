//Quản lý danh sách chuyến bay
// - Thêm chuyến bay mới (Mã chuyến bay, nơi đi, nơi đến, ngày giờ, số lượng ghế).
// - Hiển thị toàn bộ danh sách chuyến bay.(trong này có phần quản lí vé)
// - Sửa thông tin chuyến bay (chỉ cho phép sửa khi chưa có ai đặt vé).
// - Xóa chuyến bay.


#include "all_class.h"
#include <iostream>
#include <vector>
using namespace std;
airplane_ticket::airplane_ticket(){
so_luong_ve=0;
ngay_thang_bay="null";}

airplane_ticket::nhap_ve(){
cout << "Nhap ngay thang bay: ";
        cin >> ngay_thang_bay;
  cout<<"nhap so luong ve :"<<endl;
  cin>>so_luong_ve;
 ma_ve.clear();
  for(int i=0;i<so_luong_ve;i++){
    int ma;
    cout<<"nhap so luong ve thu "<<i+1<<":";
    cin>>ma;
   ma_ve.push_back(ma);
  }
 airplane_ticket::~airplane_ticket(){
     cout<<"ve co ma :"<<ma_ve
}
 void hien_thi() {
        cout << "\nNgay bay: " << ngay_thang_bay << endl;
        cout << "So luong ve: " << so_luong_ve << endl;
        cout << "Danh sach ma ve: ";
        for (int i = 0; i < ma_ve.size(); i++) {
            cout << ma_ve[i] << " ";
        }
        cout << endl;
    }
};
