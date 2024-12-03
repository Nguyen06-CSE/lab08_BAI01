#pragma once
#pragma once
void xuatMenu();
int chonMenu(int soMenu);
void xuLyMenu(int chon, DanhSachSV ds, int& n);
void ChayChuongTrinh();


void xuatMenu() {
    cout << "____________________MENU_____________________\n"
        << "0. thoat khoi chuong trinh\n"
        << "1. nhap vao danh sach mot sinh vien \n"
        << "2. in ra danh sach sinh vien\n"
        << "3. xuat danh sach theo thu tu giam dan Diem Trung Binh \n"
        << "4. xuat theo danh sach tang dan ten \n"
        << "5. tim thong tin qua ten sinh vien \n"
        << "6. xuat sanh sach sinh vien cua lop. sap xep theo ten \n"
        << "7. xuat danh sach co kha nang ko duoc tot nghiep \n"
        << "8. tim sinh vien theo MSSV \n"
        << "9. tinh ti le phan tram so sinh vien tu loai gioi tro len \n"
        << "10. xep loai hoc luc dua vao diem trung binh \n"
        << "11. thong ke ti le phan tram theo xep loai hoc luc \n"
        << "12. tinh diem trung binh cua tat ca sinh vien \n"
        << "13. cho biet do chenh lech giua sinh vien nam va nu \n"
        << "14. thong ke so luong sinh vien cua tung lop \n"
        << "15. tim va xuat nhung sinh vien co diem TB cao nhat \n";
}

int chonMenu(int soMenu) {
    int chon;
    do {
        cout << "nhap chon [0...." << soMenu << "] ";
        cin >> chon;
        if (chon >= 0 && chon <= soMenu) {
            break;
        }
    } while (true);
    return chon;
}

void xuLyMenu(int chon, DanhSachSV ds, int& n) {
    int chenhLech;
    switch (chon) {
    case 0:
        cout << "thoat khoi chuong trinh\n";
        break;
    case 1:
        cout << "nhap so luong sinh vien ban mon: "; cin >> n;
        nhapChuoiSV(ds, n);
        break;
    case 2:
        cout << "xuat " << n << " sinh vien\n";
        xuatDSSV(ds, n);
        break;
    case 3:
        xuatDSTheoDiemGiam(ds, n);
        xuatDSSV(ds, n);
        break;
    case 4:
        xapXepTheoTen(ds, n);
        xuatDSSV(ds, n);
        break;
    case 5:
        timTheoTen(ds, n);
        break;
    case 6:
        xuatSVTuLop(ds, n);
    case 7:
        cout << "\ndanh sach sinh vien co kha nang ko tot nghiep la: \n";
        xuatDSKoDuocTotNghiep(ds, n);
        break;
    case 8:
        timSVTuMSSV(ds, n);
        break;
    case 9:
        cout << "phan tram sinh vien dat loai xuat xac la " << tiLeSinhVienGioi(ds, n) << "%" << endl;
        break;
    case 10:
        XepLoai(ds, n);
        break;
    case 11:
        ThongKeTiLe(ds, n);
        break;
    case 12:
        cout << "diem trung binh cua tat ca sinh vien la: " << fixed << setprecision(3) << TinhDiemTB(ds, n) << endl;
        break;
    case 13:
        chenhLech = DoChenhLechNamNu(ds, n);
        if (chenhLech > 0)   cout << "so luong sinh vien nam nhieu hon " << chenhLech << " sinh vien nu\n";
        else if (chenhLech == 0)    cout << "so luong sinh vien nam bang so luong sinh vien nu\n";
        else    cout << "so luong sinh vien nam it hon " << -1 * chenhLech << " sinh vien nu\n";
        break;
    case 14:
        ThongKeSoLuongLop(ds, n);
        break;
    case 15:
        SinhVienDiemCao(ds, n);
        break;
    default:
        break;
    }
    _getch();
}


void ChayChuongTrinh()
{
    int soMenu = 15, chon;
    int n = 21;
    DanhSachSV ds = {
    {"2411887", "Cao Khoi", "Nguyen", "M", "CTK48", 10},
    {"2411888", "Anh Tuan", "Le", "M", "CTK48", 8.5},
    {"2411889", "Bao Chau", "Nguyen", "F", "CTK48", 9.0},
    {"2411890", "Minh Tam", "Tran", "M", "CTK49", 7.8},
    {"2411891", "Hoang Anh", "Pham", "F", "CTK49", 6.2},
    {"2411892", "Duc Minh", "Tran", "M", "CTK48", 5.5},
    {"2411893", "Lan Huong", "Nguyen", "F", "CTK50", 7.3},
    {"2411894", "Phuong Linh", "Le", "F", "CTK50", 10},
    {"2411895", "Huu Thang", "Pham", "M", "CTK48", 8.7},
    {"2411896", "Kim Ngan", "Do", "F", "CTK50", 6.8},
    {"2411897", "Minh Khang", "Le", "M", "CTK49", 9.2},
    {"2411898", "Duc Thinh", "Hoang", "M", "CTK49", 4.9},
    {"2411899", "Mai Chi", "Vu", "F", "CTK48", 8.1},
    {"2411900", "Thanh Huyen", "Nguyen", "F", "CTK50", 10},
    {"2411901", "Quoc Bao", "Tran", "M", "CTK48", 7.0},
    {"2411902", "Ngoc Bich", "Phan", "M", "CTK48", 8.4},
    {"2411903", "Hoang Kien", "Dinh", "F", "CTK49", 5.8},
    {"2411904", "Tuong Vy", "Pham", "F", "CTK50", 9.7},
    {"2411905", "Tien Dung", "Ngo", "M", "CTK48", 6.1},
    {"2411906", "Thu Hang", "Dang", "F", "CTK49", 7.9},
    {"2411907", "Van Son", "Tran", "M", "CTK48", 1.2}
    };
    do {
        system("cls");
        xuatMenu();
        chon = chonMenu(soMenu);
        xuLyMenu(chon, ds, n);
    } while (chon != 0);
}
