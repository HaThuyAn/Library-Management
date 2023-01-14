/*MSSV: 21127486
Ho ten: HA THUY AN
Lop: 21CLC07*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Header.h"

// ham viet hoa chu cai dau cua moi tu
void VietHoaChuCaiDau(char x[])
{
	for (int i = 0; i < strlen(x); i++)
	{
		if (i == 0 || (i > 0 && x[i - 1] == 32)) // viet hoa chu cai dau tien
		{
			if (x[i] >= 97 && x[i] <= 122)
			{
				x[i] = x[i] - 32;
			}
		}

		else // viet thuong chu cai ben trong
		{
			if (x[i] >= 64 && x[i] <= 90)
			{
				x[i] = x[i] + 32;
			}
		}
	}
}

// ham kiem tra ngay thang nam nhap vao co hop le hay khong
int KiemTraNgayThangNamHopLe(int Ngay, int Thang, int Nam)
{
	if (Ngay < 0 || Thang < 0 || Nam < 0)
	{
		return 0;
	}

	if (Thang > 12)
	{
		return 0;
	}

	if (Thang == 2 && Nam % 4 == 0)
	{
		if (Ngay > 29)
		{
			return 0;
		}
	}

	if (Thang == 2 && Nam % 4 != 0)
	{
		if (Ngay > 28)
		{
			return 0;
		}
	}

	if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
	{
		if (Ngay > 31)
		{
			return 0;
		}
	}

	if (Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11)
	{
		if (Ngay > 30)
		{
			return 0;
		}
	}

	return 1;
}

// ham nhap thong tin doc gia
void NhapThongTinDocGia(DocGia& DG)
{
	fflush(stdin);
	printf("Nhap ma doc gia: ");
	gets_s(DG.MaDocGia);
	_strupr_s(DG.MaDocGia); // viet hoa toan bo cac chu cai trong ma doc gia

	printf("\nNhap ho ten: ");
	gets_s(DG.HoTen);
	VietHoaChuCaiDau(DG.HoTen); // viet hoa chu cai dau cua moi tu trong ho ten nhap vao

	printf("\nNhap CMND: ");
	scanf_s("%d", &DG.CMND);

	do
	{
		printf("\nNhap ngay sinh: ");
		scanf_s("%d", &DG.NgaySinh.Ngay);

		printf("\nNhap thang sinh: ");
		scanf_s("%d", &DG.ThangSinh.Thang);

		printf("\nNhap nam sinh: ");
		scanf_s("%d", &DG.NamSinh.Nam);
		getchar();

	} while (KiemTraNgayThangNamHopLe(DG.NgaySinh.Ngay, DG.ThangSinh.Thang, DG.NamSinh.Nam) == 0); // neu kiem tra dieu kien ngay thang nam khong hop le thi doc gia phai nhap lai cho den khi hop le

	printf("\nNhap gioi tinh: ");
	gets_s(DG.GioiTinh);
	VietHoaChuCaiDau(DG.GioiTinh);

	printf("\nNhap email: ");
	gets_s(DG.Email);

	printf("\nNhap dia chi: ");
	gets_s(DG.DiaChi);
	VietHoaChuCaiDau(DG.DiaChi);

	do
	{
		printf("\nNhap ngay lap the: ");
		scanf_s("%d", &DG.NgayLapThe.Ngay);

		printf("\nNhap thang lap the: ");
		scanf_s("%d", &DG.ThangLapThe.Thang);

		printf("\nNhap nam lap the: ");
		scanf_s("%d", &DG.NamLapThe.Nam);

	} while (KiemTraNgayThangNamHopLe(DG.NgayLapThe.Ngay, DG.ThangLapThe.Thang, DG.NamLapThe.Nam) == 0); // neu kiem tra dieu kien ngay thang nam khong hop le thi doc gia phai nhap lai cho den khi hop le

	DG.NgayHetHan.Ngay = DG.NgayLapThe.Ngay;
	DG.ThangHetHan.Thang = DG.ThangLapThe.Thang;
	DG.NamHetHan.Nam = DG.NamLapThe.Nam + 4;
}

// ham them doc gia
void ThemDocGia(DocGia dsdg[], int& SoLuongDocGia)
{
	printf("\n");
	NhapThongTinDocGia(dsdg[SoLuongDocGia]);
}

// ham in ra danh sach doc gia
void XemDanhSachDocGia(DocGia dsdg[], int& SoLuongDocGia)
{
	printf("\t%15s", dsdg[SoLuongDocGia].MaDocGia);
	printf("\t%20s", dsdg[SoLuongDocGia].HoTen);
	printf("\t%12d", dsdg[SoLuongDocGia].CMND);
	printf("\t%10d/%d/%d", dsdg[SoLuongDocGia].NgaySinh.Ngay, dsdg[SoLuongDocGia].ThangSinh.Thang, dsdg[SoLuongDocGia].NamSinh.Nam);
	printf("\t%8s", dsdg[SoLuongDocGia].GioiTinh);
	printf("\t%15s", dsdg[SoLuongDocGia].Email);
	printf("\t%12s", dsdg[SoLuongDocGia].DiaChi);
	printf("\t%5d/%d/%d", dsdg[SoLuongDocGia].NgayLapThe.Ngay, dsdg[SoLuongDocGia].ThangLapThe.Thang, dsdg[SoLuongDocGia].NamLapThe.Nam);
	printf("\t%20d/%d/%d", dsdg[SoLuongDocGia].NgayHetHan.Ngay, dsdg[SoLuongDocGia].ThangHetHan.Thang, dsdg[SoLuongDocGia].NamHetHan.Nam);
	printf("\n");
}

// ham chinh sua thong tin doc gia
void ChinhSuaThongTinDocGia(DocGia dsdg[], int& SoLuongDocGia)
{
	bool Found = 0; // cho bien Found = 0

	char MaDocGia_Nhap[20];
	printf("\nNhap ma doc gia cua ban de thuc hien chinh sua thong tin: ");
	fflush(stdin);
	gets_s(MaDocGia_Nhap);
	_strupr_s(MaDocGia_Nhap); // viet hoa tat ca cac chu cai cua ma doc gia nhap vao

	for (int i = 1; i <= SoLuongDocGia; i++)
	{
		if (strcmp(dsdg[i].MaDocGia, MaDocGia_Nhap) == 0) // neu nhu ma doc gia nhap vao khop voi ma doc gia da ton tai trong danh sach thi 
		{
			Found = 1; // bien Found = 1
			
			if (Found == 1) // neu Found = 1
			{ 
				ThemDocGia(dsdg, i); // ham them doc gia duoc goi de doc gia chinh sua thong tin bang cach nhap vao thong tin moi

				printf("\nDa chinh sua thanh cong thong tin cua doc gia co ma doc gia %s!\n", dsdg[i].MaDocGia); 
			}
		}
	}

	if (Found == 0) // neu Found = 0
	{ // in ra cau sau
		printf("\nMa doc gia khong ton tai!\n");
	}
}

// ham xoa thong tin doc gia
void XoaThongTinDocGia(DocGia dsdg[], int& SoLuongDocGia)
{
	bool Found = 0; // cho bien Found = 0

	char MaDocGia_Nhap[20];
	printf("\nNhap ma doc gia de thuc hien xoa thong tin: ");
	fflush(stdin);
	gets_s(MaDocGia_Nhap);
	_strupr_s(MaDocGia_Nhap); // viet hoa tat ca cac chu cai cua ma doc gia nhap vao

	for (int i = 1; i <= SoLuongDocGia; i++) 
	{
		if (strcmp(dsdg[i].MaDocGia, MaDocGia_Nhap) == 0) // neu ma doc gia nhap vao khop voi ma doc gia da ton tai trong danh sach
		{
			Found = 1; // thi Found = 1
			
			if (Found == 1) // neu Found = 1
			{ 
				for (int j = i; j <= SoLuongDocGia - 1; j++)
				{
					dsdg[j] = dsdg[j + 1]; // thong tin doc gia tai vi tri j se duoc thay the bang thong tin cua doc gia tai vi tri j + 1
				}

				SoLuongDocGia--;
			}
		}
	}

	if (Found == 1)
	{
		printf("\nDa xoa thanh cong thong tin cua doc gia co ma doc gia %s!\n", MaDocGia_Nhap);
	}
	
	if (Found == 0) // neu Found = 0
	{ // in ra dong sau
		printf("\nMa doc gia khong ton tai!\n");
	}
}

// ham tim kiem doc gia theo cmnd
void TimKiemDocGia_CMND(DocGia dsdg[], int& SoLuongDocGia)
{
	bool Found = 0; // cho bien Found = 0

	int CMND_Nhap;
	printf("\nNhap CMND de tim kiem: ");
	scanf_s("%d", &CMND_Nhap);
	printf("\n");

	for (int i = 1; i <= SoLuongDocGia; i++)
	{
		if (dsdg[i].CMND == CMND_Nhap) // neu so cmnd nhap vao khop voi so cmnd da ton tai o trong danh sach
		{
			Found = 1; // thi Found = 1

			// sau do in ra thong tin doc gia co so cmnd do

			if (Found == 1)
			{
				printf("\n%17s \t %15s \t %10s \t %10s \t %10s \t %10s \t %15s \t %12s \t %10s", "Ma doc gia", "Ho ten", "CMND", "Ngay thang nam sinh", "Gioi tinh", "Email", "Dia chi", "Ngay thang nam lap the", "Ngay thang nam the het han");
				printf("\n");
				printf("\t%5s", dsdg[i].MaDocGia);
				printf("\t\t%10s", dsdg[i].HoTen);
				printf("\t%12d", dsdg[i].CMND);
				printf("\t%8d/%d/%d", dsdg[i].NgaySinh.Ngay, dsdg[i].ThangSinh.Thang, dsdg[i].NamSinh.Nam);
				printf("\t%15s", dsdg[i].GioiTinh);
				printf("\t\t%17s", dsdg[i].Email);
				printf("\t%10s", dsdg[i].DiaChi);
				printf("\t%5d/%d/%d", dsdg[i].NgayLapThe.Ngay, dsdg[i].ThangLapThe.Thang, dsdg[i].NamLapThe.Nam);
				printf("\t\t%10d/%d/%d", dsdg[i].NgayHetHan.Ngay, dsdg[i].ThangHetHan.Thang, dsdg[i].NamHetHan.Nam);
				printf("\n");
			}
		}
	}

	if (Found == 0) // neu Found = 0
	{ // in ra dong sau
		printf("\nCMND khong ton tai!\n");
	}
}

// ham tim kiem doc gia theo ho ten
void TimKiemDocGia_HoTen(DocGia dsdg[], int& SoLuongDocGia)
{
	bool Found = 0; // cho bien Found = 0

	char HoTen_Nhap[30];
	printf("\nNhap ho ten de tim kiem: ");
	fflush(stdin);
	gets_s(HoTen_Nhap);
	VietHoaChuCaiDau(HoTen_Nhap); // viet hoa chu cai dau cua moi tu trong ho ten doc gia nhap vao

	for (int i = 1; i <= SoLuongDocGia; i++)
	{
		if (strcmp(dsdg[i].HoTen, HoTen_Nhap) == 0) // neu ho ten nhap vao khop voi ho ten da ton tai trong danh sach 
		{
			Found = 1; // thi Found = 1

			// in ra thong tin doc gia co ho ten do

			if (Found == 1)
			{
				printf("\n%17s \t %15s \t %10s \t %10s \t %10s \t %10s \t %15s \t %12s \t %10s", "Ma doc gia", "Ho ten", "CMND", "Ngay thang nam sinh", "Gioi tinh", "Email", "Dia chi", "Ngay thang nam lap the", "Ngay thang nam the het han");
				printf("\n");
				printf("\t%5s", dsdg[i].MaDocGia);
				printf("\t\t%10s", dsdg[i].HoTen);
				printf("\t%12d", dsdg[i].CMND);
				printf("\t%8d/%d/%d", dsdg[i].NgaySinh.Ngay, dsdg[i].ThangSinh.Thang, dsdg[i].NamSinh.Nam);
				printf("\t%15s", dsdg[i].GioiTinh);
				printf("\t\t%17s", dsdg[i].Email);
				printf("\t%10s", dsdg[i].DiaChi);
				printf("\t%5d/%d/%d", dsdg[i].NgayLapThe.Ngay, dsdg[i].ThangLapThe.Thang, dsdg[i].NamLapThe.Nam);
				printf("\t\t%10d/%d/%d", dsdg[i].NgayHetHan.Ngay, dsdg[i].ThangHetHan.Thang, dsdg[i].NamHetHan.Nam);
				printf("\n");
			}
		}
	}

	if (Found == 0) // neu Found = 0
	{ // in ra dong sau
		printf("\nHo ten khong ton tai!\n");
	}
}

// ham luu thong tin doc gia vao file
void XuatDanhSachDocGia_VaoFile(DG dsdg[], int SoLuongDocGia)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\DocGia.bin", "wb");

	if (f == NULL)
	{
		return;
	}

	fwrite(&SoLuongDocGia, sizeof(SoLuongDocGia), 1, f);

	for (int i = 1; i <= SoLuongDocGia; i++)
	{
		fwrite(&dsdg[i], sizeof(DG), 1, f);
	}

	fclose(f);
}

// ham lay thong tin doc gia tu file 
void NhapDanhSachDocGia_TuFile(DG dsdg[], int& SoLuongDocGia)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\DocGia.bin", "rb");

	if (f == NULL)
	{
		return;
	}

	fread(&SoLuongDocGia, sizeof(SoLuongDocGia), 1, f);

	for (int i = 1; i <= SoLuongDocGia; i++)
	{
		fread(&dsdg[i], sizeof(DG), 1, f);
	}

	fclose(f);
}

// ham nhap thong tin sach
void NhapThongTinSach(Sach& S)
{
	fflush(stdin);
	printf("\nNhap ma sach: ");
	gets_s(S.MaSach);
	_strupr_s(S.MaSach);

	printf("\nNhap ten sach: ");
	gets_s(S.TenSach);
	VietHoaChuCaiDau(S.TenSach);

	printf("\nNhap ten tac gia: ");
	gets_s(S.TacGia);
	VietHoaChuCaiDau(S.TacGia);

	printf("\nNhap ten nha xuat ban: ");
	gets_s(S.NhaXuatBan);
	VietHoaChuCaiDau(S.NhaXuatBan);

	printf("\nNhap nam xuat ban: ");
	scanf_s("%d", &S.NamXuatBan.Nam);
	getchar();

	printf("\nNhap the loai: ");
	gets_s(S.TheLoai);
	VietHoaChuCaiDau(S.TheLoai);

	printf("\nNhap gia sach: ");
	scanf_s("%d", &S.GiaSach);
	
	printf("\nNhap so quyen sach: ");
	scanf_s("%d", &S.SoQuyenSach);
}

// ham them sach
void ThemSach(Sach dss[], int& SoLuongSach)
{
	NhapThongTinSach(dss[SoLuongSach]);
}

// ham in ra danh sach sach
void XemDanhSachSach(Sach dss[], int& SoLuongSach)
{
	printf("\t%25s", dss[SoLuongSach].MaSach);
	printf("\t%15s", dss[SoLuongSach].TenSach);
	printf("\t%15s", dss[SoLuongSach].TacGia);
	printf("\t%15s", dss[SoLuongSach].NhaXuatBan);
	printf("\t%18d", dss[SoLuongSach].NamXuatBan.Nam);
	printf("\t%23s", dss[SoLuongSach].TheLoai);
	printf("\t%20d dong", dss[SoLuongSach].GiaSach);
	printf("\t%10d quyen", dss[SoLuongSach].SoQuyenSach);
	printf("\n");
}

// ham chinh sua thong tin sach
void ChinhSuaThongTinSach(Sach dss[], int& SoLuongSach)
{
	bool Found = 0; 

	char MaSach_Nhap[20];
	printf("\nNhap ma sach de thuc hien chinh sua thong tin: ");
	fflush(stdin);
	gets_s(MaSach_Nhap);
	_strupr_s(MaSach_Nhap);

	for (int i = 1; i <= SoLuongSach; i++)
	{
		if (strcmp(dss[i].MaSach, MaSach_Nhap) == 0)
		{
			Found = 1;
			
			if (Found == 1)
			{
				ThemSach(dss, i);

				printf("\nDa chinh sua thanh cong thong tin cua sach co ma sach %s!\n", dss[i].MaSach);
			}
		}
	}

	if (Found == 0)
	{
		printf("\nMa sach khong ton tai!\n");
	}
}

// ham xoa thong tin sach
void XoaThongTinSach(Sach dss[], int& SoLuongSach)
{
	bool Found = 0;

	char MaSach_Nhap[20];
	printf("\nNhap ma sach de thuc hien xoa thong tin: ");
	fflush(stdin);
	gets_s(MaSach_Nhap);
	_strupr_s(MaSach_Nhap);

	for (int i = 1; i <= SoLuongSach; i++)
	{
		if (strcmp(dss[i].MaSach, MaSach_Nhap) == 0)
		{
			Found = 1;
			
			if (Found == 1)
			{
				for (int j = i; j <= SoLuongSach - 1; j++)
				{
					dss[j] = dss[j + 1];
				}

				SoLuongSach--;
			}
		}
	}

	if (Found == 1)
	{
		printf("\nDa xoa thanh cong thong tin cua sach co ma sach %s!\n", MaSach_Nhap);
	}

	if (Found == 0)
	{
		printf("\nMa sach khong ton tai!\n");
	}
}

// ham tim kiem sach theo ma sach
void TimKiemSach_ISBN(Sach dss[], int& SoLuongSach)
{
	bool Found = 0;

	char MaSach_Nhap[20];
	printf("\nNhap ma sach de tim kiem: ");
	gets_s(MaSach_Nhap);
	_strupr_s(MaSach_Nhap);
	printf("\n");

	for (int i = 1; i <= SoLuongSach; i++)
	{
		if (strcmp(dss[i].MaSach, MaSach_Nhap) == 0)
		{
			Found = 1;

			if (Found == 1)
			{
				printf("\n %15s \t %15s \t %20s \t %15s \t %15s \t %15s \t %15s \t %15s", "Ma sach", "Ten sach", "Tac gia", "Nha xuat ban", "Nam xuat ban", "The loai", "Gia sach", "So quyen sach");
				printf("\n");
				printf("\t%10s", dss[i].MaSach);
				printf("\t%15s", dss[i].TenSach);
				printf("\t%15s", dss[i].TacGia);
				printf("\t%15s", dss[i].NhaXuatBan);
				printf("\t%18d", dss[i].NamXuatBan.Nam);
				printf("\t%23s", dss[i].TheLoai);
				printf("\t%20d dong", dss[i].GiaSach);
				printf("\t%10d quyen", dss[i].SoQuyenSach);
				printf("\n");
			}
		}
	}

	if (Found == 0)
	{
		printf("\nMa sach khong ton tai!\n");
	}
}

// ham tim kiem sach theo ten sach
void TimKiemSach_TenSach(Sach dss[], int& SoLuongSach)
{
	bool Found = 0;

	char TenSach_Nhap[50];
	printf("\nNhap ten sach de tim kiem: ");
	gets_s(TenSach_Nhap);
	VietHoaChuCaiDau(TenSach_Nhap);

	for (int i = 1; i <= SoLuongSach; i++)
	{
		if (strcmp(dss[i].TenSach, TenSach_Nhap) == 0)
		{
			Found = 1;

			if (Found == 1)
			{
				printf("\n %15s \t %15s \t %20s \t %15s \t %15s \t %15s \t %15s \t %15s", "Ma sach", "Ten sach", "Tac gia", "Nha xuat ban", "Nam xuat ban", "The loai", "Gia sach", "So quyen sach");
				printf("\n");
				printf("\t%10s", dss[i].MaSach);
				printf("\t%15s", dss[i].TenSach);
				printf("\t%15s", dss[i].TacGia);
				printf("\t%15s", dss[i].NhaXuatBan);
				printf("\t%18d", dss[i].NamXuatBan.Nam);
				printf("\t%23s", dss[i].TheLoai);
				printf("\t%20d dong", dss[i].GiaSach);
				printf("\t%10d quyen", dss[i].SoQuyenSach);
				printf("\n");
			}
		}
	}

	if (Found == 0)
	{
		printf("\nTen sach khong ton tai!\n");
	}
}

// ham luu thong tin cac sach vao file
void XuatDanhSachSach_VaoFile(S dss[], int SoLuongSach)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\Sach.bin", "wb");

	if (f == NULL)
	{
		return;
	}

	fwrite(&SoLuongSach, sizeof(SoLuongSach), 1, f);

	for (int i = 1; i <= SoLuongSach; i++)
	{
		fwrite(&dss[i], sizeof(S), 1, f);
	}

	fclose(f);
}

// ham lay thong tin cac sach tu file
void NhapDanhSachSach_TuFile(S dss[], int& SoLuongSach)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\Sach.bin", "rb");

	if (f == NULL)
	{
		return;
	}

	fread(&SoLuongSach, sizeof(SoLuongSach), 1, f);

	for (int i = 1; i <= SoLuongSach; i++)
	{
		fread(&dss[i], sizeof(S), 1, f);
	}

	fclose(f);
}

// ham nhap thong tin phieu muon sach
void NhapThongTin_PhieuMuonSach(PhieuMuonSach &PMS)
{
	do
	{
		printf("\nNhap ngay muon: ");
		scanf_s("%d", &PMS.NgayMuon.Ngay);

		printf("\nNhap thang muon: ");
		scanf_s("%d", &PMS.ThangMuon.Thang);

		printf("\nNhap nam muon: ");
		scanf_s("%d", &PMS.NamMuon.Nam);

	} while (KiemTraNgayThangNamHopLe(PMS.NgayMuon.Ngay, PMS.ThangMuon.Thang, PMS.NamMuon.Nam) == 0); // neu kiem tra dieu kien ngay thang nam khong hop le thi doc gia se phai nhap lai cho den khi hop le

	do
	{
		printf("\nNhap ngay tra du kien: ");
		scanf_s("%d", &PMS.NgayTra_DuKien.Ngay);

		printf("\nNhap thang tra du kien: ");
		scanf_s("%d", &PMS.ThangTra_DuKien.Thang);

		printf("\nNhap nam tra du kien: ");
		scanf_s("%d", &PMS.NamTra_DuKien.Nam);

	} while (KiemTraNgayThangNamHopLe(PMS.NgayTra_DuKien.Ngay, PMS.ThangTra_DuKien.Thang, PMS.NamTra_DuKien.Nam) == 0); // neu kiem tra dieu kien ngay thang nam khong hop le thi doc gia se phai nhap lai cho den khi hop le
}

// ham them ma sach vao danh sach cac sach muon
void ThemMaSachVaoDanhSach_Muon(PhieuMuonSach pms[], int &SoSachMuon_DocGia, int &SoLuongDocGia)
{
	printf("\nNhap ma sach muon: ");
	gets_s(pms[SoSachMuon_DocGia].MaSach_Muon.MaSach);
	_strupr_s(pms[SoSachMuon_DocGia].MaSach_Muon.MaSach);
}

// ham xuat ra danh sach cac sach muon
void XuatDanhSachCacMaSach_Muon(PhieuMuonSach pms[], int& SoSachMuon_DocGia, int &SoLuongDocGia)
{
	printf("\n%s", pms[SoSachMuon_DocGia].MaSach_Muon.MaSach);
}

// ham thuc hien cac chuc nang lien quan den phieu muon sach
void Phieu_MuonSach(DocGia dsdg[], PhieuMuonSach pms[], int& SoSachMuon_DocGia, int &SoSachMuon, int &SoLuongDocGia)
{
	printf("\nNhap ma doc gia de thuc hien muon sach: ");
	gets_s(pms[SoLuongDocGia].MaDocGia_Muon.MaDocGia);
	_strupr_s(pms[SoLuongDocGia].MaDocGia_Muon.MaDocGia);

	int m = 1; // khoi gan bien m = 1

	SoSachMuon_DocGia = 0;

	for (int i = 1; i <= SoLuongDocGia; i++)
	{
		if (strcmp(dsdg[i].MaDocGia, pms[SoLuongDocGia].MaDocGia_Muon.MaDocGia) == 0)
		{
			printf("\nVui long nhap thong tin duoi day de muon sach!\n");
			while (m == 1) // neu m = 1 thi cac cau lenh trong dau {} duoi day se duoc lap lai
			{
				SoSachMuon++; // moi lan m = 1 thi so sach muon + 1

				SoSachMuon_DocGia++; // tao bien tam thoi: SoSachMuon_DocGia

				ThemMaSachVaoDanhSach_Muon(pms, SoSachMuon_DocGia, i);
				printf("\nChon 1 de them sach, chon 0 de tiep tuc!\n"); // neu chon 1 thi <=> m = 1 
				printf("\nChon: ");
				scanf_s("%d", &m);
				getchar();
			}
			NhapThongTin_PhieuMuonSach(pms[i]);

			// in ra phieu muon sach
			printf("\nPHIEU MUON SACH SO %d", i);
			printf("\n");
			printf("\nMa doc gia: %s", pms[SoLuongDocGia].MaDocGia_Muon.MaDocGia);
			printf("\nNgay thang nam muon sach: %d/%d/%d", pms[i].NgayMuon.Ngay, pms[i].ThangMuon.Thang, pms[i].NamMuon.Nam);
			printf("\nNgay thang nam tra sach du kien: %d/%d/%d", pms[i].NgayTra_DuKien.Ngay, pms[i].ThangTra_DuKien.Thang, pms[i].NamTra_DuKien.Nam);
			printf("\nDanh sach ISBN cua cac sach muon:");

			for (int j = 1; j <= SoSachMuon_DocGia; j++)
			{
				XuatDanhSachCacMaSach_Muon(pms, j, i); // in ra danh sach cac sach muon
			}

			SoSachMuon_DocGia = 0; // gan bien tam thoi = 0 de khi bat dau sang doc gia moi thi danh sach cac sach muon in ra se chinh xac

			printf("\n");
		}
	}
}

// ham luu thong tin ngay thang nam doc gia thuc hien muon sach vao file de tinh toan so ngay muon khi tra sach
void XuatNgayThangNamMuon_VaoFile(DocGia dsdg[], PhieuMuonSach pms[], int SoLuongDocGia)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\Ngay thang nam muon sach.bin", "wb");

	if (f == NULL)
	{
		return;
	}

	fwrite(&SoLuongDocGia, sizeof(DG), 1, f);

	for (int i = 1; i <= SoLuongDocGia; i++)
	{
		fwrite(&pms[i].NgayMuon.Ngay, sizeof(PMS), 1, f);

		fwrite(&pms[i].ThangMuon.Thang, sizeof(PMS), 1, f);

		fwrite(&pms[i].NamMuon.Nam, sizeof(PMS), 1, f);
	}

	fclose(f);
}

// ham lay thong tin ngay thang nam doc gia muon sach tu file de tinh toan so ngay muon khi tra sach
void NhapNgayThangNamMuon_TuFile(DocGia dsdg[], PhieuMuonSach pms[], int& SoLuongDocGia)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\Ngay thang nam muon sach.bin", "rb");

	if (f == NULL)
	{
		return;
	}

	fread(&SoLuongDocGia, sizeof(DG), 1, f);

	for (int i = 1; i <= SoLuongDocGia; i++)
	{
		fread(&pms[i].NgayMuon.Ngay, sizeof(PMS), 1, f);

		fread(&pms[i].ThangMuon.Thang, sizeof(PMS), 1, f);

		fread(&pms[i].NamMuon.Nam, sizeof(PMS), 1, f);
	}

	fclose(f);
}

// ham nhap thong tin phieu tra sach
void NhapThongTin_PhieuTraSach(PhieuTraSach& PTS)
{
	do
	{
		printf("\nNhap ngay tra sach thuc te: ");
		scanf_s("%d", &PTS.NgayTra_ThucTe.Ngay);
		getchar();

		printf("\nNhap thang tra sach thuc te: ");
		scanf_s("%d", &PTS.ThangTra_ThucTe.Thang);
		getchar();

		printf("\nNhap nam tra sach thuc te: ");
		scanf_s("%d", &PTS.NamTra_ThucTe.Nam);
		getchar();

	} while (KiemTraNgayThangNamHopLe(PTS.NgayTra_ThucTe.Ngay, PTS.ThangTra_ThucTe.Thang, PTS.NamTra_ThucTe.Nam) == 0); // neu kiem tra dieu kien ngay thang nam khong hop le thi doc gia se phai nhap lai cho den khi hop le
}

// ham them ma sach vao danh sach cac sach tra
void ThemMaSachVaoDanhSach_Tra(PhieuTraSach pts[], int& SoSachTra_DocGia, int& SoLuongDocGia)
{
	printf("\nNhap ma sach tra: ");
	gets_s(pts[SoSachTra_DocGia].MaSach_Tra.MaSach);
	_strupr_s(pts[SoSachTra_DocGia].MaSach_Tra.MaSach);
}

// ham xuat danh sach cac ma sach tra
void XuatDanhSachCacMaSach_Tra(PhieuTraSach pts[], int& SoSachTra_DocGia, int& SoLuongDocGia)
{
	printf("\n%s", pts[SoSachTra_DocGia].MaSach_Tra.MaSach);
}

// ham tinh so ngay trong mot thang bat ki
int SoNgayTrongThang(int Thang, int Nam)
{
	int SoNgay = 0;

	switch (Thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		SoNgay = 31;
		break;

	case 4:
	case 6:
	case 9: 
	case 11:
		SoNgay = 30;
		break;

	case 2:
	{
		if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0)
		{
			SoNgay = 29;
		}
		else
		{
			SoNgay = 28;
		}
		break;
	}
	}
	return SoNgay;
}

// ham tinh so thu tu cua ngay bat ki trong nam
int TinhSoThuTuCuaNgayTrongNam(int Ngay, int Thang, int Nam)
{
	int countDay = Ngay;

	if (KiemTraNgayThangNamHopLe(Ngay, Thang, Nam) == 1)
	{
		for (int i = 1; i <= Thang - 1; i++)
		{
			countDay = countDay + SoNgayTrongThang(Thang, Nam);
		}
	}

	return countDay;
}

// ham kiem tra tre han
void KiemTraTreHan(DocGia dsdg[], Sach dss[], PhieuMuonSach pms[], PhieuTraSach pts[], int& SoSachBiTreHan, int& SoLuongDocGia, int& SoLuongSach)
{
	// so thu tu cua ngay doc gia muon sach trong nam
	int SoThuTuCuaNgayMuonTrongNam = TinhSoThuTuCuaNgayTrongNam(pms[SoLuongDocGia].NgayMuon.Ngay, pms[SoLuongDocGia].ThangMuon.Thang, pms[SoLuongDocGia].NamMuon.Nam);

	// so thu tu cua ngay doc gia tra sach trong nam
	int SoThuTuCuaNgayTraTrongNam = TinhSoThuTuCuaNgayTrongNam(pts[SoLuongDocGia].NgayTra_ThucTe.Ngay, pts[SoLuongDocGia].ThangTra_ThucTe.Thang, pts[SoLuongDocGia].NamTra_ThucTe.Nam);

	// so ngay da muon = so thu tu cua ngay doc gia tra sach trong nam - so thu tu cua ngay doc gia muon sach trong nam
	int SoNgayDaMuon = SoThuTuCuaNgayTraTrongNam - SoThuTuCuaNgayMuonTrongNam;

	// so ngay tre han = so ngay da muon - 7
	int SoNgayTreHan = SoNgayDaMuon - 7;

	if (SoNgayTreHan <= 0) // neu so ngay tre han be hon hoac bang 0
	{
		printf("\nBan da tra sach DUNG HAN!\n");
	}
	else // nguoc lai neu so ngay tre han lon hon 0
	{
		SoSachBiTreHan++; // so sach bi tra tre han + 1

		printf("\nBan da tra sach TRE HAN!\n");

		printf("\nVui long nhap thong tin duoi day!\n");

		printf("\nNhap ma doc gia: ");
		gets_s(pts[SoSachBiTreHan].MaDocGia_TreHan.MaDocGia);
		_strupr_s(pts[SoSachBiTreHan].MaDocGia_TreHan.MaDocGia);

		printf("\nNhap ma sach bi tra tre han: ");
		gets_s(pts[SoSachBiTreHan].MaSach_TreHan.MaSach);
		_strupr_s(pts[SoSachBiTreHan].MaSach_TreHan.MaSach);

		pts[SoSachBiTreHan].TongTienPhaiTra_TreHan = 0;

		int Found1 = 1; // cho bien Found1 = 1

		int Found2 = 1; // cho bien Found2 = 1

		for (int i = 1; i <= SoLuongDocGia; i++)
		{
			if (strcmp(dsdg[i].MaDocGia, pts[SoSachBiTreHan].MaDocGia_TreHan.MaDocGia) == 0) // neu ma doc gia nhap vao khop voi ma doc gia da ton tai trong danh sach
			{
				Found1 = 1; // thi Found1 = 1

				for (int j = 1; j <= SoLuongSach; j++)
				{
					if (strcmp(dss[j].MaSach, pts[SoSachBiTreHan].MaSach_TreHan.MaSach) == 0) // neu ma sach nhap vao khop voi ma sach da ton tai trong danh sach
					{
						Found2 = 1; // thi Found2 = 1

						for (int t = 1; t <= SoNgayTreHan; t++) // cho bien t = 1, chay toi = so ngay tre han (tre han 1 ngay lap 1 lan, tre han 2 ngay lap 2 lan, ... moi lan lap + 5000)
						{
							pts[SoSachBiTreHan].TongTienPhaiTra_TreHan = pts[SoSachBiTreHan].TongTienPhaiTra_TreHan + 5000;
						}
					}
				}
			}
		}

		// neu 1 trong 2 bien Found1 hoac Found2 = 0
		if ((Found1 == 0 && Found2 == 1) || (Found1 == 0 && Found2 == 0)) 
		{
			printf("\nMa doc gia khong ton tai!");
		}

		else if ((Found1 == 1 && Found2 == 0) || (Found1 == 0 && Found2 == 0))
		{
			printf("\nMa sach khong ton tai!");
		}

		// neu ca hai bien Found1 va Found2 = 1
		else if (Found1 == 1 && Found2 == 1)
		{
			// thi in ra so tien phai tra do tra cuon sach do tre han
			printf("\nSo tien doc gia %s phai tra do tre han cuon sach %s la %d dong!\n", pts[SoSachBiTreHan].MaDocGia_TreHan.MaDocGia, pts[SoSachBiTreHan].MaSach_TreHan.MaSach, pts[SoSachBiTreHan].TongTienPhaiTra_TreHan);
		}
	}
}

// ham kiem tra doc gia co lam mat sach hay khong
void KiemTraMatSach(PhieuTraSach pts[], DocGia dsdg[], Sach dss[], int &SoLuongSach, int &SoLuongDocGia, int &SoSachMuon, int &SoSachMat)
{
	int l;
	
	int e = 1; // khoi gan bien e = 1

	int Found1 = 1; // cho bien Found1 = 1

	int Found2 = 1; // cho bien Found2 = 1

	printf("\nBan co lam mat cuon sach nao khong???\n");
	printf("\nNeu co thi chon 1, con khong thi chon 0!\n");
	printf("\nChon: ");
	scanf_s("%d", &l); 
	getchar();

	if (l == 0) // neu l = 0 <=> khong mat sach
	{
		printf("\nCam on vi ban da khong lam mat sach.\n");
	}

	else if (l == 1) // neu l = 1 <=> mat sach
	{
		while (e == 1) // khi nao doc gia con chon e = 1 thi cac cau lenh trong {} se con duoc lap lai
		{
			SoSachMat++; // so sach mat + 1 cho moi lan lap

			printf("\nBan da lam mat sach. Ban se phai tra tien den bu cho thu vien!\n");

			printf("\nNhap ma doc gia cua ban: ");
			gets_s(pts[SoSachMat].MaDocGia_MatSach.MaDocGia);
			_strupr_s(pts[SoSachMat].MaDocGia_MatSach.MaDocGia);

			printf("\nVui long nhap ma sach cua sach ban da lam mat!\n");
			printf("\nMa sach: ");
			gets_s(pts[SoSachMat].MaSach_MatSach.MaSach);
			_strupr_s(pts[SoSachMat].MaSach_MatSach.MaSach);

			for (int i = 1; i <= SoLuongDocGia; i++)
			{
				if (strcmp(dsdg[i].MaDocGia, pts[SoSachMat].MaDocGia_MatSach.MaDocGia) == 0) // neu ma doc gia nhap vao khop voi ma doc gia da ton tai trong danh sach
				{
					Found1 = 1; // thi Found1 = 1

					for (int j = 1; j <= SoLuongSach; j++)
					{
						if (strcmp(pts[SoSachMat].MaSach_MatSach.MaSach, dss[j].MaSach) == 0) // neu ma sach nhap vao khop voi ma sach da ton tai trong danh sach
						{
							Found2 = 1; // thi Found2 = 1

							pts[SoSachMat].TongTienPhaiTra_MatSach = dss[j].GiaSach * 2; 
						}
					}
				}
			}

			// neu 1 trong 2 bien Found1 hoac Found2 = 0
			if ((Found1 == 0 && Found2 == 1) || (Found1 == 0 && Found2 == 0))
			{
				printf("\nMa doc gia khong ton tai!\n");
			}

			else if ((Found1 == 1 && Found2 == 0) || (Found1 == 0 && Found2 == 0))
			{
				printf("\nMa sach khong ton tai!\n");
			}

			else if (Found1 == 1 && Found2 == 1)
			{
				// in ra so tien phai tra do lam mat cuon sach nao do
				printf("\nSo tien doc gia %s phai tra do lam mat cuon sach %s la %d dong!\n", pts[SoSachMat].MaDocGia_MatSach.MaDocGia, pts[SoSachMat].MaSach_MatSach.MaSach, pts[SoSachMat].TongTienPhaiTra_MatSach);
				SoSachMuon--;
			}

			printf("\nBan con lam mat cuon sach nao nua khong?\n");
			printf("\nNeu con thi chon 1, khong thi chon 0 de tiep tuc!\n");
			printf("\nChon: ");
			scanf_s("%d", &e);
			getchar();
		}
	}
}

// ham thuc hien cac chuc nang co trong phieu tra sach
void Phieu_TraSach(DocGia dsdg[], Sach dss[], PhieuMuonSach pms[], PhieuTraSach pts[], int &SoSachTra_DocGia, int &SoLuongDocGia, int &SoSachMuon, int &SoLuongSach, int &SoSachBiTreHan, int &SoSachMat)
{
	char MaDocGia_Nhap[20];
	printf("\nNhap ma doc gia cua ban de thu vien xac nhan danh tinh: ");
	gets_s(MaDocGia_Nhap);
	_strupr_s(MaDocGia_Nhap);

	int m = 1; // khoi tao bien m = 1

	SoSachTra_DocGia = 0; // tao bien tam thoi: SoSachTra_DocGia
	
	for (int i = 1; i <= SoLuongDocGia; i++)
	{
		if (strcmp(dsdg[i].MaDocGia, MaDocGia_Nhap) == 0)
		{
			while (m == 1) // khi nao m con = 1 thi vong lap se con duoc lap lai
			{
				SoSachTra_DocGia++; 

				ThemMaSachVaoDanhSach_Tra(pts, SoSachTra_DocGia, i);

				SoSachMuon--; // so sach muon - 1

				printf("\nChon 1 de them sach, chon 0 de tiep tuc!\n");
				printf("\nChon: ");
				scanf_s("%d", &m);
				getchar();
			}

			NhapThongTin_PhieuTraSach(pts[i]);

			// in ra phieu tra sach
			printf("\nPHIEU TRA SACH SO %d", i);
			printf("\nMa doc gia: %s", MaDocGia_Nhap);
			printf("\nNgay thang nam muon sach: %d/%d/%d", pms[i].NgayMuon.Ngay, pms[i].ThangMuon.Thang, pms[i].NamMuon.Nam);
			printf("\nNgay thang nam tra sach thuc te: %d/%d/%d\n", pts[i].NgayTra_ThucTe.Ngay, pts[i].ThangTra_ThucTe.Thang, pts[i].NamTra_ThucTe.Nam);

			for (int j = 1; j <= SoSachTra_DocGia; j++)
			{
				KiemTraTreHan(dsdg, dss, pms, pts, SoSachBiTreHan, i, SoLuongSach);
			}

			SoSachTra_DocGia = 0; // cho bien tam thoi = 0 de khi doc gia moi lap phieu tra sach thi danh sach cac sach tra in ra se chinh xac

			KiemTraMatSach(pts, dsdg, dss, SoLuongSach, i, SoSachMuon, SoSachMat);
		}
	}
}

// ham thong ke so luong sach trong thu vien
void ThongKeSoLuongSachTrongThuVien(Sach dss[], int &SoLuongSach)
{
	int TongSoSach = 0;

	for (int i = 1; i <= SoLuongSach; i++)
	{
		TongSoSach = TongSoSach + dss[i].SoQuyenSach; // tong so sach = so quyen sach cua moi cuon sach
	}

	printf("\nSo luong sach co trong thu vien la %d quyen.\n", TongSoSach);
}

// ham thong ke so luong sach theo the loai
void ThongKeSoLuongSachTheoTheLoai(Sach dss[], int& SoLuongSach) // co 3 loai sach trong thu vien
{
	// khoi gan tat ca so sach cua cac the loai = 0
	int SoSach_CS = 0;

	int SoSach_E = 0;

	int SoSach_M = 0;

	int SoSach_NS = 0;

	// quet qua danh sach de dem so luong cua the loai do
	for (int i = 1; i <= SoLuongSach; i++)
	{
		if (strcmp("Computer Science", dss[i].TheLoai) == 0)
		{
			SoSach_CS = SoSach_CS + dss[i].SoQuyenSach;
		}

		if (strcmp("Economics", dss[i].TheLoai) == 0)
		{
			SoSach_E = SoSach_E + dss[i].SoQuyenSach;
		}

		if (strcmp("Mathematics", dss[i].TheLoai) == 0)
		{
			SoSach_M = SoSach_M + dss[i].SoQuyenSach;
		}

		if (strcmp("Neuroscience", dss[i].TheLoai) == 0)
		{
			SoSach_NS = SoSach_NS + dss[i].SoQuyenSach;
		}
	}

	// in ra so luong sach theo the loai
	printf("\nSo sach Computer Science la: %d quyen\n", SoSach_CS);
	printf("\nSo sach Economics la: %d quyen\n", SoSach_E);
	printf("\nSo sach Maths la: %d quyen\n", SoSach_M);
	printf("\nSo sach Neuroscience la: %d quyen\n", SoSach_NS);
}

// ham thong ke so luong doc gia
void ThongKeSoLuongDocGia(DocGia dsdg[], int& SoLuongDocGia)
{
	printf("\nSo luong doc gia co trong thu vien la: %d\n", SoLuongDocGia);
}

// ham thong ke so luong doc gia theo gioi tinh
void ThongKeSoLuongDocGiaTheoGioiTinh(DocGia dsdg[], int& SoLuongDocGia)
{
	// cho so luong moi gioi tinh = 0

	int SoDocGia_Nu = 0;
	
	int SoDocGia_Nam = 0;

	// quet qua danh sach de dem so luong doc gia theo gioi tinh
	for (int i = 1; i <= SoLuongDocGia; i++)
	{
		if (strcmp("Nu", dsdg[i].GioiTinh) == 0)
		{
			SoDocGia_Nu++;
		}

		if (strcmp("Nam", dsdg[i].GioiTinh) == 0)
		{
			SoDocGia_Nam++;
		}
	}

	// in ra so luong doc gia theo gioi tinh
	printf("\nSo doc gia nu co trong thu vien la: %d\n", SoDocGia_Nu);
	printf("\nSo doc gia nam co trong thu vien la: %d\n", SoDocGia_Nam);
}

// ham thong ke so luong sach dang duoc muon
void ThongKeSoSachDangDuocMuon(int& SoSachMuon)
{
	printf("\nSo sach dang duoc muon la: %d\n", SoSachMuon);
}

// ham luu so luong sach dang duoc muon vao file
void XuatSoSachDangDuocMuon_VaoFile(int SoSachMuon)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\So sach dang duoc muon.bin", "wb");

	if (f == NULL)
	{
		return;
	}

	fwrite(&SoSachMuon, sizeof(SoSachMuon), 1, f);

	fclose(f);
}

// ham lay so luong sach dang duoc muon tu file
void NhapSoSachDangDuocMuon_TuFile(int &SoSachMuon)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\So sach dang duoc muon.bin", "rb");

	if (f == NULL)
	{
		return;
	}

	fread(&SoSachMuon, sizeof(SoSachMuon), 1, f);

	fclose(f);
}

// ham thong ke danh sach doc gia bi tre han
void ThongKeDanhSachDocGiaBiTreHan(PhieuTraSach pts[], int &SoSachBiTreHan)
{
	if (SoSachBiTreHan <= 0)
	{
		printf("\nKhong co doc gia nao tra sach tre han!\n");
	}

	else
	{
		// in ra danh sach doc gia tre han tra sach
		printf("\nDANH SACH DOC GIA TRE HAN TRA SACH\n");

		for (int i = 1; i <= SoSachBiTreHan; i++)
		{
			printf("\nSO THU TU %d\n", i);
			printf("\nMa doc gia: %s\n", pts[i].MaDocGia_TreHan.MaDocGia);
			printf("\nMa sach: %s\n", pts[i].MaSach_TreHan.MaSach);
		}
	}
}

// ham luu so sach bi tre han vao file
void XuatSoSachBiTreHan_VaoFile(int SoSachBiTreHan)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\So sach bi tre han.bin", "wb");

	if (f == NULL)
	{
		return;
	}

	fwrite(&SoSachBiTreHan, sizeof(SoSachBiTreHan), 1, f);

	fclose(f);
}

// ham lay so sach bi tre han tu file
void NhapSoSachBiTreHan_TuFile(int& SoSachBiTreHan)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\So sach bi tre han.bin", "rb");

	if (f == NULL)
	{
		return;
	}

	fread(&SoSachBiTreHan, sizeof(SoSachBiTreHan), 1, f);

	fclose(f);
}

// ham luu thong tin doc gia tre han vao file
void XuatDocGiaTreHan_VaoFile(PhieuTraSach pts[], int SoSachBiTreHan)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\Doc gia tre han.bin", "wb");

	if (f == NULL)
	{
		return;
	}

	fwrite(&SoSachBiTreHan, sizeof(SoSachBiTreHan), 1, f);

	for (int i = 1; i <= SoSachBiTreHan; i++)
	{
		fwrite(&pts[i].MaDocGia_TreHan.MaDocGia, sizeof(PTS), 1, f);

		fwrite(&pts[i].MaSach_TreHan.MaSach, sizeof(PTS), 1, f);
	}

	fclose(f);
}

// ham lay thong tin doc gia tre han tu file
void NhapDocGiaTreHan_TuFile(PhieuTraSach pts[], int &SoSachBiTreHan)
{
	FILE* f;
	errno_t err = fopen_s(&f, "D:\\Doc gia tre han.bin", "rb");

	if (f == NULL)
	{
		return;
	}

	fread(&SoSachBiTreHan, sizeof(SoSachBiTreHan), 1, f);

	for (int i = 1; i <= SoSachBiTreHan; i++)
	{
		fread(&pts[i].MaDocGia_TreHan.MaDocGia, sizeof(PTS), 1, f);

		fread(&pts[i].MaSach_TreHan.MaSach, sizeof(PTS), 1, f);
	}

	fclose(f);
}