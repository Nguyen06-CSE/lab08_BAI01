#pragma once
#pragma once
#define MAX 100

struct SinhVien {
    //char MSSV[8], ho[31], ten[11], gioiTinh, lop[11];
    string MSSV, ho, ten, gioiTinh, lop;
    double diem;
};

typedef SinhVien DanhSachSV[MAX];

void nhap1SV(SinhVien& a);
void xuat1SV(SinhVien a);
void xuatDSSV(DanhSachSV ds, int n);
void hoanVi(SinhVien& a, SinhVien& b);
bool sapXepGiam(double a, double b);
void xapXepTheoTen(DanhSachSV ds, int n);
void xuatSVTuLop(DanhSachSV ds, int n);
void xuatDSKoDuocTotNghiep(DanhSachSV ds, int n);
void timSVTuMSSV(DanhSachSV ds, int n);
double tiLeSinhVienGioi(DanhSachSV ds, int n);
void ThongKeTiLe(DanhSachSV ds, int n);
double TinhDiemTB(DanhSachSV ds, int n);
double DoChenhLechNamNu(DanhSachSV ds, int n);
void ThongKeSoLuongLop(DanhSachSV ds, int n);
void SinhVienDiemCao(DanhSachSV ds, int n);



void nhap1SV(SinhVien& a) {
    cout << "nhap MSSV: ";
    cin >> a.MSSV;
    cin.ignore();  

    cout << "nhap ho va ten dem: ";
    getline(cin, a.ho);

    cout << "nhap ten sinh vien: ";
    cin >> a.ten;  

    cout << "nhap gioi tinh (M la nam, F la nu): ";
    cin >> a.gioiTinh;

    cout << "nhap lop: ";
    cin >> a.lop;

    cout << "nhap diem: ";
    cin >> a.diem;
}
void xuat1SV(SinhVien a) {
    cout << "\n" << setiosflags(ios::left)
        << setw(10) << a.MSSV
        << setw(15) << a.ho
        << setw(7) << a.ten
        << setw(8) << a.gioiTinh
        << setw(10) << a.lop
        << setw(10) << fixed << setprecision(2) << a.diem ;
}


void nhapChuoiSV(DanhSachSV ds, int& n) {
    for (int i = 0; i < n; i++) {
        cout << "nhap sinh vien thu " << i + 1 << endl;
        cout << "nhap MSSV: ";
        cin >> ds[i].MSSV;
        cout << "nhap ho va ten dem: ";
        cin.ignore();
        getline(cin, ds[i].ho);
        cout << "nhap ten sinh vien: ";
        cin >> ds[i].ten;
        cout << "nhap gioi tinh (M la nam, F la nu): ";
        cin >> ds[i].gioiTinh;
        cout << "nhap lop: ";
        cin >> ds[i].lop;
        cout << "nhap diem: ";
        cin >> ds[i].diem;

    }
}

void xuatDSSV(DanhSachSV ds, int n) {
    cout << "\n" << setiosflags(ios::left)
        << setw(10) << "MSSV"
        << setw(15) << "HO"
        << setw(7) << "TEN"
        << setw(8) << "GIOI TINH"
        << setw(10) << "LOP"
        << setw(10) << "Diem" << endl
        <<"______________________________________________________________\n";
    for (int i = 0; i < n; i++)
        cout << "\n" << setiosflags(ios::left)
            << setw(10) << ds[i].MSSV
            << setw(15) << ds[i].ho
            << setw(7) << ds[i].ten
            << setw(8) << ds[i].gioiTinh
            << setw(10) << ds[i].lop
            << setw(10) << ds[i].diem << endl;
}

bool sapXepGiam(double a, double b) {
    return a > b;
}

void hoanVi(SinhVien& a, SinhVien& b) {
    SinhVien tmp = a;
    a = b;
    b = tmp;
}

void xuatDSTheoDiemGiam(DanhSachSV ds, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sapXepGiam(ds[j].diem, ds[i].diem)) {
                hoanVi(ds[i], ds[j]);
            }
        }
    }
}

void xapXepTheoTen(DanhSachSV ds, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int kt = ds[i].ten.compare(ds[j].ten) ;
            if (kt > 0) hoanVi(ds[i], ds[j]);

            if (kt == 0) {
                int ktHo = ds[i].ho.compare(ds[j].ho);
                if (ktHo > 0) hoanVi(ds[i], ds[j]);
            }

        }
    }
}

void timTheoTen(DanhSachSV ds, int n) {
    cout << "nhap ten sinh vien ban muon tim kiem: ";
    char ten[11]; cin >> ten;
    for (int i = 0; i < n; i++) {
        int kt = ds[i].ten.compare(ten);
        if (kt == 0) xuat1SV(ds[i]);

    }
    cout << ten << " ko ton tai trong danh sach\n";

}

void xuatSVTuLop(DanhSachSV ds, int n) {
    char lop[11];
    int k = 0;
    cout << "Nhap lop ban muon tim kiem sinh vien: "; cin >> lop;
    for (int i = 0; i < n; i++) {
        int kt = ds[i].lop.compare(lop);
        if (kt == 0) {
            ds[k] = ds[i];
            ++k;
        }
    }
    xapXepTheoTen(ds, k);
    for (int i = 0; i < k; i++) {
        xuat1SV(ds[i]);
    }
}

void xuatDSKoDuocTotNghiep(DanhSachSV ds, int n) {
    for (int i = 0; i < n; i++) {
        if (ds[i].diem < 5) xuat1SV(ds[i]);
    }
}

void timSVTuMSSV(DanhSachSV ds, int n) {
    char ma[8];
    cout << "hay nhap MSSV ban muon tim kiem: "; cin >> ma;
    for (int i = 0; i < n; i++) {
        int kt = ds[i].MSSV.compare(ma);
        if (kt == 0) xuat1SV(ds[i]);
        else    cout << ma << " ko ton tai trong danh sach\n";
    }
    
}

double tiLeSinhVienGioi(DanhSachSV ds, int n) {
    double result;
    int dem = 0;
    for (int i = 0;i < n; i++) {
        if (ds[i].diem >= 8) ++dem;
    }
    return (double)dem / n * 100;
}

void XepLoai(DanhSachSV ds, int n) {
    cout << "\n" << setiosflags(ios::left)
        << setw(10) << "MSSV"
        << setw(15) << "HO"
        << setw(7) << "TEN"
        << setw(8) << "GIOI TINH"
        << setw(10) << "LOP"
        << setw(10) << "DIEM" 
        << setw(10) << "XEP LOAI" << endl
        << "________________________________________________________________________________\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].diem >= 9.0 && ds[i].diem <= 10.0) {
            xuat1SV(ds[i]);
            cout << " Xuat sac" << endl;
        }
        else if (ds[i].diem >= 8.0 && ds[i].diem <= 9.0) {
            xuat1SV(ds[i]);
            cout << " Gioi" << endl;
        }
        else if (ds[i].diem >= 7.0 && ds[i].diem <= 8.0) {
            xuat1SV(ds[i]);
            cout << " Kha" << endl;
        }
        else if (ds[i].diem >= 6.5 && ds[i].diem <= 7.0) {
            xuat1SV(ds[i]);
            cout << " Trung binh kha" << endl;
        }
        else if (ds[i].diem >= 5.0 && ds[i].diem <= 6.5) {
            xuat1SV(ds[i]);
            cout << " Trung binh" << endl;
        }
        else if (ds[i].diem >= 3.0 && ds[i].diem <= 5.0) {
            xuat1SV(ds[i]);
            cout << " Yeu" << endl;
        }
        else
        {
            xuat1SV(ds[i]);
            cout << " Kem" << endl;
        }
    }
}


void ThongKeTiLe(DanhSachSV ds, int n)
{
    int xuatXac = 0, gioi = 0, kha = 0, TBK = 0, TB = 0, yeu = 0, kem = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].diem >= 9.0 && ds[i].diem <= 10.0) {
            ++xuatXac;
        }
        else if (ds[i].diem >= 8.0 && ds[i].diem <= 9.0) {
            ++gioi;
        }
        else if (ds[i].diem >= 7.0 && ds[i].diem <= 8.0) {
            ++kha;
        }
        else if (ds[i].diem >= 6.5 && ds[i].diem <= 7.0) {
            ++TBK;
        }
        else if (ds[i].diem >= 5.0 && ds[i].diem <= 6.5) {
            ++TB;
        }
        else if (ds[i].diem >= 3.0 && ds[i].diem <= 5.0) {
            ++yeu;
        }
        else
        {
            ++kem;
        }
    }
    cout << "ti le hoc sinh Xuat Xac la: " << (double)xuatXac / (double)n * 100 << "%\n";
    cout << "ti le hoc sinh Gioi la: " << (double)gioi / (double)n * 100 << "%\n";
    cout << "ti le hoc sinh Kha la: " << (double)kha / (double)n * 100 << "%\n";
    cout << "ti le hoc sinh Trung Binh Kha la: " << (double)TBK / (double)n * 100 << "%\n";
    cout << "ti le hoc sinh Trung Binh la: " << (double)TB / (double)n * 100 << "%\n";
    cout << "ti le hoc sinh Yeu la: " << (double)yeu / (double)n * 100 << "%\n";
    cout << "ti le hoc sinh Kem la: " << (double)kem / (double)n * 100 << "%\n";
}

double TinhDiemTB(DanhSachSV ds, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].diem;
    }
    return (double)tong / (double)n;
}

double DoChenhLechNamNu(DanhSachSV ds, int n)
{
    double demNam = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].gioiTinh == "m" || ds[i].gioiTinh == "M") {
            ++demNam;
        }
    }
    int demNu = n - demNam;
    int chenhLech = demNam - demNu;
    
    return chenhLech;
}

void ThongKeSoLuongLop(DanhSachSV ds, int n) {
    bool mangKT[MAX] = { false };
    for (int i = 0; i < n; i++) {
        if (!mangKT[i]) {
            int dem = 1;
            for (int j = i + 1; j < n; j++) {   
                int kt = ds[i].lop.compare(ds[j].lop);
                if (kt == 0 && !mangKT[j]) {
                    ++dem;
                    mangKT[j] = true;
                }
            }
            cout << "lop " << ds[i].lop << " co so sinh vien la: " << dem << endl;
        }
    }
}




void SinhVienDiemCao(DanhSachSV ds, int n)
{
    cout << "sinh vien co diem cao nhat trong danh sach la: \n";

    int maxVal = 0;
    for (int i = 0; i < n; i++) 
        if (maxVal < ds[i].diem) maxVal = ds[i].diem;
    for (int j = 0; j < n; j++) {
        if (ds[j].diem == maxVal) {
            xuat1SV(ds[j]);
        }
    }
}

