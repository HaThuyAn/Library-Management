/*MSSV: 21127486
Ho ten: HA THUY AN
Lop: 21CLC07*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Header.h"

void main()
{
	int SoLuongDocGia = 0;
	DocGia DG;
	DocGia dsdg[100];
	
	int SoLuongSach = 0;
	Sach S;
	Sach dss[100];

	int SoSachMuon = 0;
	int SoSachMuon_DocGia;

	PhieuMuonSach pms[100];
	Sach dssm[100];

	PhieuTraSach pts[100];
	int SoSachTra_DocGia;
	int SoSachBiTreHan = 0;
	int SoSachMat = 0;

	int n = 1; // khoi gan bien n = 1 de chay vong lap while lan dau tien
	int Option;
	while (n == 1) // khi nao n con bang 1 thi vong while nay con lap lai
	{
		printf("CHAO MUNG DEN VOI THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN TPHCM\n");
		printf("       VUI LONG NHAP SO TUONG UNG TRONG MENU DE LUA CHON!\n        ");
		printf("-------------------- MENU ---------------------\n");
		printf("  I. QUAN LI DOC GIA.\n");
		printf("  1. Xem danh sach doc gia trong thu vien.\n");
		printf("  2. Them doc gia.\n");
		printf("  3. Chinh sua thong tin doc gia.\n");
		printf("  4. Xoa thong tin doc gia.\n");
		printf("  5. Tim kiem doc gia theo CMND.\n");
		printf("  6. Tim kiem doc gia theo ho ten.\n");
		printf(" II. QUAN LI SACH.\n");
		printf("  7. Xem danh sach cac sach trong thu vien.\n");
		printf("  8. Them sach.\n");
		printf("  9. Chinh sua thong tin sach.\n");
		printf(" 10. Xoa thong tin sach.\n");
		printf(" 11. Tim kiem sach theo ISBN.\n");
		printf(" 12. Tim kiem sach theo ten sach.\n");
		printf("III. MUON SACH.\n");
		printf(" 13. Lap phieu muon sach.\n");
		printf(" IV. TRA SACH.\n");
		printf(" 14. Lap phieu tra sach.\n");
		printf("  V. CAC THONG KE CO BAN.\n");
		printf(" 15. Thong ke so luong sach trong thu vien.\n");
		printf(" 16. Thong ke so luong sach theo the loai.\n");
		printf(" 17. Thong ke so luong doc gia.\n");
		printf(" 18. Thong ke so luong doc gia theo gioi tinh.\n");
		printf(" 19. Thong ke so luong sach dang duoc muon.\n");
		printf(" 20. Thong ke danh sach doc gia bi tre han.\n");
		printf("\nMoi ban nhap su lua chon: ");
		scanf_s("%d", &Option);
		getchar();

		NhapDanhSachDocGia_TuFile(dsdg, SoLuongDocGia);
		NhapDanhSachSach_TuFile(dss, SoLuongSach);

		switch (Option)
		{
		case 1:
		{
			NhapDanhSachDocGia_TuFile(dsdg, SoLuongDocGia);
			printf("\n %10s \t %13s \t %15s \t %10s \t %10s \t %10s \t %10s \t %15s \t %10s \t %10s", "So thu tu", "Ma doc gia", "Ho ten", "CMND", "Ngay thang nam sinh", "Gioi tinh", "Email", "Dia chi", "Ngay thang nam lap the", "Ngay thang nam the het han");
			printf("\n");
			for (int i = 1; i <= SoLuongDocGia; i++)
			{
				printf("%8d", i);
				XemDanhSachDocGia(dsdg, i);
			}
			break;
		}
		case 2:
		{
			SoLuongDocGia++;
			ThemDocGia(dsdg, SoLuongDocGia);
			XuatDanhSachDocGia_VaoFile(dsdg, SoLuongDocGia);
			break;
		}
		case 3:
		{
			ChinhSuaThongTinDocGia(dsdg, SoLuongDocGia);
			XuatDanhSachDocGia_VaoFile(dsdg, SoLuongDocGia);
			break;
		}
		case 4:
		{
			XoaThongTinDocGia(dsdg, SoLuongDocGia);
			XuatDanhSachDocGia_VaoFile(dsdg, SoLuongDocGia);
			break;
		}
		case 5:
		{
			TimKiemDocGia_CMND(dsdg, SoLuongDocGia);
			break;
		}
		case 6:
		{
			TimKiemDocGia_HoTen(dsdg, SoLuongDocGia);
			break;
		}
		case 7:
		{
			NhapDanhSachSach_TuFile(dss, SoLuongSach);
			printf("\n %15s \t %15s \t %15s \t %20s \t %15s \t %15s \t %15s \t %15s \t %15s", "So thu tu", "Ma sach", "Ten sach", "Tac gia", "Nha xuat ban", "Nam xuat ban", "The loai", "Gia sach", "So quyen sach");
			printf("\n");
			for (int i = 1; i <= SoLuongSach; i++)
			{
				printf("%15d", i);
				XemDanhSachSach(dss, i);
			}
			break;
		}
		case 8:
		{
			SoLuongSach++;
			ThemSach(dss, SoLuongSach);
			XuatDanhSachSach_VaoFile(dss, SoLuongSach);
			break;
		}
		case 9:
		{
			ChinhSuaThongTinSach(dss, SoLuongSach);
			XuatDanhSachSach_VaoFile(dss, SoLuongSach);
			break;
		}
		case 10:
		{
			XoaThongTinSach(dss, SoLuongSach);
			XuatDanhSachSach_VaoFile(dss, SoLuongSach);
			break;
		}
		case 11:
		{
			TimKiemSach_ISBN(dss, SoLuongSach);
			break;
		}
		case 12:
		{
			TimKiemSach_TenSach(dss, SoLuongSach);
			break;
		}
		case 13:
		{
			Phieu_MuonSach(dsdg, pms, SoSachMuon_DocGia, SoSachMuon, SoLuongDocGia);
			XuatSoSachDangDuocMuon_VaoFile(SoSachMuon);
			XuatNgayThangNamMuon_VaoFile(dsdg, pms, SoLuongDocGia);
			break;
		}
		case 14:
		{
			NhapSoSachBiTreHan_TuFile(SoSachBiTreHan);
			NhapDocGiaTreHan_TuFile(pts, SoSachBiTreHan);
			NhapNgayThangNamMuon_TuFile(dsdg, pms, SoLuongDocGia);
			Phieu_TraSach(dsdg, dss, pms, pts, SoSachTra_DocGia, SoLuongDocGia, SoSachMuon, SoLuongSach, SoSachBiTreHan, SoSachMat);
			XuatSoSachDangDuocMuon_VaoFile(SoSachMuon);
			XuatSoSachBiTreHan_VaoFile(SoSachBiTreHan);
			XuatDocGiaTreHan_VaoFile(pts, SoSachBiTreHan);
			break;
		}
		case 15:
		{
			ThongKeSoLuongSachTrongThuVien(dss, SoLuongSach);
			break;
		}
		case 16:
		{
			ThongKeSoLuongSachTheoTheLoai(dss, SoLuongSach);
			break;
		}
		case 17:
		{
			ThongKeSoLuongDocGia(dsdg, SoLuongDocGia);
			break;
		}
		case 18:
		{
			ThongKeSoLuongDocGiaTheoGioiTinh(dsdg, SoLuongDocGia);
			break;
		}
		case 19:
		{
			NhapSoSachDangDuocMuon_TuFile(SoSachMuon);
			ThongKeSoSachDangDuocMuon(SoSachMuon);
			break;
		}
		case 20:
		{
			NhapSoSachBiTreHan_TuFile(SoSachBiTreHan);
			NhapDocGiaTreHan_TuFile(pts, SoSachBiTreHan);
			ThongKeDanhSachDocGiaBiTreHan(pts, SoSachBiTreHan);
			break;
		}
		}
		printf("\nChon 1 de tiep tuc chuong trinh, chon 0 de thoat!");
		printf("\n\nChon: ");
		scanf_s("%d", &n);
		printf("\n");
	}
}