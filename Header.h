/*MSSV: 21127486
Ho ten: HA THUY AN
Lop: 21CLC07*/

#pragma once
struct Date
{
	int Ngay;
	int Thang;
	int Nam;
};

struct DocGia
{
	char MaDocGia[20];
	char HoTen[30];
	int CMND;
	Date NgaySinh;
	Date ThangSinh;
	Date NamSinh;
	char GioiTinh[10];
	char Email[30];
	char DiaChi[50];
	Date NgayLapThe;
	Date ThangLapThe;
	Date NamLapThe;
	Date NgayHetHan;
	Date ThangHetHan;
	Date NamHetHan;
};
typedef DocGia DG;
void VietHoaChuCaiDau(char x[]);
int KiemTraNgayThangNamHopLe(int Ngay, int Thang, int Nam);
void NhapThongTinDocGia(DocGia& DG);
void XemDanhSachDocGia(DocGia dsdg[], int& SoLuongDocGia);
void ThemDocGia(DocGia dsdg[], int& SoLuongDocGia);
void ChinhSuaThongTinDocGia(DocGia dsdg[], int& SoLuongDocGia);
void XoaThongTinDocGia(DocGia dsdg[], int& SoLuongDocGia);
void TimKiemDocGia_CMND(DocGia dsdg[], int& SoLuongDocGia);
void TimKiemDocGia_HoTen(DocGia dsdg[], int& SoLuongDocGia);
void XuatDanhSachDocGia_VaoFile(DG dsdg[], int SoLuongDocGia);
void NhapDanhSachDocGia_TuFile(DG dsdg[], int &SoLuongDocGia);

struct Sach
{
	char MaSach[20];
	char TenSach[50];
	char TacGia[50];
	char NhaXuatBan[50];
	Date NamXuatBan;
	char TheLoai[50];
	int GiaSach;
	int SoQuyenSach;
};
typedef Sach S;
void NhapThongTinSach(Sach& S);
void XemDanhSachSach(Sach dss[], int& SoLuongSach);
void ThemSach(Sach dss[], int& SoLuongSach);
void ChinhSuaThongTinSach(Sach dss[], int& SoLuongSach);
void XoaThongTinSach(Sach dss[], int& SoLuongSach);
void TimKiemSach_ISBN(Sach dss[], int& SoLuongSach);
void TimKiemSach_TenSach(Sach dss[], int& SoLuongSach);
void XuatDanhSachSach_VaoFile(S dss[], int SoLuongSach);
void NhapDanhSachSach_TuFile(S dss[], int& SoLuongSach);


struct PhieuMuonSach
{
	Date NgayMuon;
	Date ThangMuon;
	Date NamMuon;
	Date NgayTra_DuKien;
	Date ThangTra_DuKien;
	Date NamTra_DuKien;
	DocGia MaDocGia_Muon;
	Sach MaSach_Muon;
};
typedef PhieuMuonSach PMS;
void NhapThongTin_PhieuMuonSach(PhieuMuonSach& PMS);
void ThemMaSachVaoDanhSach_Muon(PhieuMuonSach pms[], int& SoSachMuon_DocGia, int& SoLuongDocGia);
void XuatDanhSachCacMaSach_Muon(PhieuMuonSach pms[], int& SoSachMuon_DocGia, int& SoLuongDocGia);
void Phieu_MuonSach(DocGia dsdg[], PhieuMuonSach pms[], int& SoSachMuon_DocGia, int& SoSachMuon, int& SoLuongDocGia);
void XuatNgayThangNamMuon_VaoFile(DocGia dsdg[], PhieuMuonSach pms[], int SoLuongDocGia);
void NhapNgayThangNamMuon_TuFile(DocGia dsdg[], PhieuMuonSach pms[], int& SoLuongDocGia);

struct PhieuTraSach
{
	Date NgayTra_ThucTe;
	Date ThangTra_ThucTe;
	Date NamTra_ThucTe;
	DocGia MaDocGia_Tra;
	Sach MaSach_Tra;
	DocGia MaDocGia_TreHan;
	Sach MaSach_TreHan;
	int TongTienPhaiTra_TreHan;
	DocGia MaDocGia_MatSach;
	Sach MaSach_MatSach;
	int TongTienPhaiTra_MatSach;
};
typedef PhieuTraSach PTS;
void NhapThongTin_PhieuTraSach(PhieuTraSach& PTS);
void ThemMaSachVaoDanhSach_Tra(PhieuTraSach pts[], int& SoSachTra_DocGia, int& SoLuongDocGia);
void XuatDanhSachCacMaSach_Tra(PhieuTraSach pts[], int& SoSachTra_DocGia, int& SoLuongDocGia);
int SoNgayTrongThang(int Thang, int Nam);
int TinhSoThuTuCuaNgayTrongNam(int Ngay, int Thang, int Nam);
void KiemTraTreHan(DocGia dsdg[], Sach dss[], PhieuMuonSach pms[], PhieuTraSach pts[], int& SoSachBiTreHan, int& SoLuongDocGia, int& SoLuongSach);
void KiemTraMatSach(PhieuTraSach pts[], DocGia dsdg[], Sach dss[], int& SoLuongSach, int& SoLuongDocGia, int& SoSachMuon, int &SoSachMat);
void Phieu_TraSach(DocGia dsdg[], Sach dss[], PhieuMuonSach pms[], PhieuTraSach pts[], int& SoSachTra_DocGia, int& SoLuongDocGia, int& SoSachMuon, int& SoLuongSach, int& SoSachBiTreHan, int &SoSachMat);

void ThongKeSoLuongSachTrongThuVien(Sach dss[], int& SoLuongSach);
void ThongKeSoLuongSachTheoTheLoai(Sach dss[], int& SoLuongSach);
void ThongKeSoLuongDocGia(DocGia dsdg[], int& SoLuongDocGia);
void ThongKeSoLuongDocGiaTheoGioiTinh(DocGia dsdg[], int& SoLuongDocGia);
void ThongKeSoSachDangDuocMuon(int& SoSachMuon);
void XuatSoSachDangDuocMuon_VaoFile(int SoSachMuon);
void NhapSoSachDangDuocMuon_TuFile(int& SoSachMuon);
void ThongKeDanhSachDocGiaBiTreHan(PhieuTraSach pts[], int& SoSachBiTreHan);
void XuatSoSachBiTreHan_VaoFile(int SoSachBiTreHan);
void NhapSoSachBiTreHan_TuFile(int& SoSachBiTreHan);
void XuatDocGiaTreHan_VaoFile(PhieuTraSach pts[], int SoSachBiTreHan);
void NhapDocGiaTreHan_TuFile(PhieuTraSach pts[], int &SoSachBiTreHan);