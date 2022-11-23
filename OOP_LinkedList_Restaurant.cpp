// Library
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <unistd.h>
using namespace std;

// class restoran
class MasakanPadang
{
public:
  // atribut
  string menu;
  int hargaPaket, jumlahMenu;

  MasakanPadang *next, *head, *tail, *cur, *newNode, *del, *before;

  // membuat single linked list
  void createNode(string menu, int hargaPaket)
  {
    head = new MasakanPadang();
    head->menu = menu;
    head->hargaPaket = hargaPaket;
    head->next = NULL;
    tail = head;
  }

  // print single linked list
  int countNode()
  {
    cur = head;
    int jumlah = 0;
    while (cur != NULL)
    {
      jumlah++;
      cur = cur->next;
    }
    return jumlah;
  }

  // menambahkan node di akhir single linked list
  void addLast(string menu, int hargaPaket)
  {
    newNode = new MasakanPadang();
    newNode->menu = menu;
    newNode->hargaPaket = hargaPaket;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }

// menghapus node di awal single linked list
  void removeFirst()
  {
    del = head;
    head = head->next;
    delete del;
  }

// menghapus node di akhir single linked list
  void removeLast()
  {
    del = tail;
    cur = head;
    while (cur->next != tail)
    {
      cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
  }
  // gabungan penghapusan node
  void removeNode(int posisi)
  {
    if (posisi < 1 || posisi > countNode())
    {
      cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
      removeFirst();
    }
    else if (posisi == countNode())
    {
      removeLast();
    }

    else
    {
      int nomor = 1;
      cur = head;
      while (nomor <= posisi)
      {
        if (nomor == posisi - 1)
        {
          before = cur;
        }
        if (nomor == posisi)
        {
          del = cur;
        }
        cur = cur->next;
        nomor++;
      }
      before->next = cur;
      delete del;
    }
  }
  // ubah node di awal single linked list
  void changeFirst(string menu, int hargaPaket)
  {
    head->menu = menu;
    head->hargaPaket = hargaPaket;
  }

  // ubah di akhir single linked list
  void changeLast(string menu, int hargaPaket)
  {
    tail->menu = menu;
    tail->hargaPaket = hargaPaket;
  }
  void changeNode(string menu, int hargaPaket, int posisi)
  {
    if (posisi < 1 || posisi > countNode())
    {
      cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
      changeFirst(menu, hargaPaket);
    }
    else if (posisi == countNode())
    {
      changeLast(menu, hargaPaket);
    }
    else
    {
      cur = head;
      int nomor = 1;
      while (nomor != posisi)
      {
        cur = cur->next;
        nomor++;
      }
      cur->menu = menu;
      cur->hargaPaket = hargaPaket;
    }
  }

// menampilkan isi setiap node
  void displayNode()
  {
    int i = 1;
    cout << "\nJumlah data ada : " << countNode() << endl;
    if (countNode() == 0)
    {
      cout << "Menu kosong";
    }
    else
    {
      cur = head;
      cout << "\n========================================= \n";
      cout << "|\t    ~~Daftar Menu~~ \t\t|\n";
      cout << "----------------------------------------- \n";
      while (cur != NULL)
      {

        cout << "|" << i << "." << cur->menu << "\t\tHarga: Rp " << cur->hargaPaket << "\t|" << endl;
        cur = cur->next;
        i++;
      }
    }
  }
};

vector<int> &operator<<(vector<int> &option, int const chooseMenu)
{
  option.push_back(chooseMenu);
}
loading()
{
  for (int j = 0; j < 1; j++)
  {
    cout << "\rLoading   \rLoading";
    for (int i = 0; i < 3; i++)
    {
      cout << ".";
      sleep(1);
    }
  }
  cout << endl;
}
// kelas turunan pelanggan
class Pelanggan : public MasakanPadang
{
public:
  string namaPelanggan, choose;
  int nomorMeja, input, harga, chooseMenu, delMenu, totalHarga, uangUser, pos;
  vector<int> total, option, jmlh;
  void choice()
  {
    cout << "\n\n======== Masakan Padang ======== \n";
    cout << "--> 1. Pilihan Menu \n";
    cout << "--> 2. Hapus Menu \n";
    cout << "--> 3. Tambah Menu \n";
    cout << "--> 4. Ubah Menu \n";
    cout << "--> 5. Menu Pembayaran \n";
    cout << "--> 99. Exit \n";
    cout << "--> Input: ";
    cin >> input;

    //  Jika memilih "1" akan memunculkan pilihan menu
    if (input == 1)
    {
      displayNode();
    tess:
      cout << "\nMasukkan pilihan menu: ";
      cin >> chooseMenu;
      option << chooseMenu;
      if (chooseMenu <= countNode())
      {

        cout << "Masukkan jumlah menu: ";
        cin >> jumlahMenu;
        jmlh.push_back(jumlahMenu);

        int nomor = 1;
        cur = head;
        while (nomor != chooseMenu)
        {
          cur = cur->next;
          nomor++;
        }
        cout << "Pesanan yang dipilih: " << endl;
        cout << nomor << "." << cur->menu << " x" << jumlahMenu << "\t\tHarga: Rp " << jumlahMenu * cur->hargaPaket << endl;
        total.push_back(jumlahMenu * cur->hargaPaket);
      }
      else
      {
        cout << "Menu tidak ada di list";
      }
    pilihanTambah:
      cout << "\nApakah ingin menambah pesanan (y/n)? ";
      cin >> choose;
      if (choose == "y")
      {
        goto tess;
      }
      else if (choose == "n")
      {
      }
      else if (choose != "y" || choose != "n")
      {
        cout << "Pilihan anda di luar jangkauan";
        goto pilihanTambah;
      }

      loading();
      system("cls");
      choice();
    }

    // Jika memilih "2" akan menuju fitur hapus menu
    else if (input == 2)
    {
      displayNode();
      cout << "\nPilih menu yang ingin dihapus: ";
      cin >> delMenu;
      if (delMenu <= countNode())
      {
        removeNode(delMenu);
      }
      else
      {
        cout << "Menu tidak ada di list \n";
      }
      loading();
      system("cls");
      choice();
    }

    // Jika memilih "3" akan menuju ke fitur tambah menu
    else if (input == 3)
    {
      displayNode();
      cin.ignore();
      cout << "\nMasukkan menu pesanan: ";
      getline(cin, menu);
      cout << "Masukkan harga: ";
      cin >> harga;
      addLast(menu, harga);
      loading();
      system("cls");
      choice();
    }

    // Jika memilih "4" akan menuju ke fitur ubah menu
    else if (input == 4)
    {
      displayNode();
      cout << "\nPilih menu yang ingin diubah: ";
      cin >> pos;
      if (pos <= countNode())
      {
        cin.ignore();
        cout << "Masukkan menu terbaru: ";
        getline(cin, menu);
        cout << "Masukkan harga terbaru: ";
        cin >> harga;
        changeNode(menu, harga, pos);
      }
      else
      {
        cout << "Menu tidak ada di list \n";
      }
      loading();
      system("cls");
      choice();
    }

    // Jika memilih "5" akan menuju ke menu pembayaran
    else if (input == 5)
    {
      totalHarga = accumulate(total.begin(), total.end(), 0);
      if (totalHarga == 0)
      {
        cout << "\nAnda belum memesan makanan\n";
        loading();
        system("cls");
        choice();
      }
      system("cls");
      cout << "Nama: " << namaPelanggan;
      cout << "\nNomor Meja: " << nomorMeja;
      cout << "\nJumlah Pesanan: " << option.size();
      cout << "\n\nDetail pesanan anda sebagai berikut \n";
      for (int i = 0; i < option.size(); i++)
      {
        int nomor = 1;
        cur = head;

        // Angka di kanan nomor != untuk indeks nodenya
        while (nomor != option[i])
        {
          cur = cur->next;
          nomor++;
        }

        cout << i + 1 << "." << cur->menu << " x" << jmlh[i] << "   \tHarga: Rp " << jmlh[i] * cur->hargaPaket << endl;
      }
      cout << "\nPembayaran \n";
      cout << "\nTotal Yang Harus Dibayarkan:\t"
           << "Rp " << totalHarga;
      cout << "\nUang Pelanggan: \t\tRp ";
      cin >> uangUser;
      if (uangUser < totalHarga)
      {
        payment(uangUser, totalHarga);
      }
      else if (uangUser > totalHarga)
      {
        int uangKembali;
        uangKembali = uangUser - totalHarga;
        payment(uangKembali);
      }
      else
      {
        cout << "\nPembayaran diterima";
        cout << "\n========================================" << endl;
        cout << "\nHave a nice day!" << endl;
      }
      exit(0);
    }

    // Jika memilih "99" program akan selesai
    else if (input == 99)
    {
      exit(0);
    }
    else
    {
      cout << "Pilihan di luar jangkauan";
      choice();
    }
  }

  void payment(int x, int y)
  {
    int uangSisa;
    cout << "Uang tidak mencukupi\n";
    cout << "\nSilahkan membayar sisanya dengan cashless\n";

    cout << "Nominal yang tepat: "
         << "Rp " << y - x << endl;
  bayarUlang:
    cout << "Scan QR code dan masukkan nominal: Rp ";
    cin >> uangSisa;

    if (uangSisa == (y - x))
    {
      cout << "\nPembayaran diterima";
      cout << "\n========================================" << endl;
      cout << "\nHave a nice day!" << endl;
    }
    else if (uangSisa < y - x)
    {
      goto bayarUlang;
    }
    else if (uangSisa > y - x)
    {
      goto bayarUlang;
    }
  }

  void payment(int x)
  {
    cout << "\nPembayaran diterima";
    cout << "\nUang Kembalian: \t\t"
         << "Rp " << x << endl;
    cout << "\n========================================" << endl;
    cout << "\nHave a nice day!" << endl;
  }
};

int main()
{
  string button;
  loading();
  cout << endl;
  // cout << "Press any button to continue: ";
  // cin >> button;
  system("cls");
  Pelanggan customer;
  cout << "\nMasukkan nomor meja: ";
  cin >> customer.nomorMeja;
  cout << "Masukkan nama pelanggan: ";
  cin >> customer.namaPelanggan;
  customer.createNode("Nasi Rendang", 22000);
  customer.addLast("Nasi Sop Iga", 30000);
  customer.addLast("Nasi Kambing", 20000);
  customer.addLast("Teh Hangat", 4000);
  customer.choice();
}