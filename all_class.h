include<bits/stdc++.h>
using namespace std;
class airplane_ticket{
int so_luong_ve;
vector<int>ma_ve;
string ngay_thang_bay;
public:
airplane_ticket()

so_luong_ve=0;
ngay_thang_bay="null";

nhap_ve(){
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
  ~airplane_ticket(){
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


