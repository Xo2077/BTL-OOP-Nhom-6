//Quản lý danh sách chuyến bay
// - Thêm chuyến bay mới (Mã chuyến bay, nơi đi, nơi đến, ngày giờ, số lượng ghế).
// - Hiển thị toàn bộ danh sách chuyến bay.(trong này có phần quản lí vé)
// - Sửa thông tin chuyến bay (chỉ cho phép sửa khi chưa có ai đặt vé).
// - Xóa chuyến bay.


#include "all_class.h"
#include <iostream>
#include <vector>
using namespace std;

vector<Task> taskList;

void addTask() {
    Task t;
    cout << "Nhap ten cong viec: ";
    getline(cin, t.name);
    cout << "Nguoi thuc hien: ";
    getline(cin, t.assignee);
    cout << "Trang thai: ";
    getline(cin, t.status);
    cout << "Muc do uu tien (1-3): ";
    cin >> t.priority;
    cin.ignore();
    taskList.push_back(t);
}

void showAllTasks() {
    cout << "\n=== DANH SACH CONG VIEC ===\n";
    for (auto &t : taskList) {
        cout << "- " << t.name << " | " << t.assignee << " | " << t.status << " | Priority: " << t.priority << endl;
    }
}
