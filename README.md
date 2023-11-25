<h1 align="center">Sistem Pendeteksi Banjir dengan Arduino Uno dan Telegram
</h1>

<p align="center">
  <img src="https://www.arduino.cc/en/uploads/Trademark/ArduinoCommunityLogo.png" />
</p>

## Deskripsi Singkat
Sistem ini memanfaatkan Arduino Uno dengan sensor ketinggian air (HC-SR04) untuk mendeteksi banjir. Ketika tinggi air melebihi ambang batas yang ditetapkan, sistem memberi notifikasi melalui Telegram. Komunikasi ke Telegram dilakukan melalui modul WiFi ESP8266-ESP01. Informasi mengenai ketinggian air dan status sistem ditampilkan pada LCD 16x2, sementara buzzer memberikan peringatan suara jika terjadi banjir.

## Komponen yang Digunakan
- **Arduino Uno**: Mikrokontroler utama untuk mengendalikan sistem.
- **Sensor Ketinggian Air (HC-SR04)**: Digunakan untuk mengukur tinggi air.
- **Modul WiFi ESP8266-01**: Untuk koneksi ke jaringan WiFi dan mengirim notifikasi ke Telegram.
- **LCD 16x2 I2C**: Untuk menampilkan informasi seperti status sistem atau tinggi air.
- **Buzzer**: Untuk memberi peringatan suara jika terdeteksi banjir.
- **1k Ohm Resistor**: Untuk mengatur arus pada transistor.
- **Transistor NPN 2N2222**: Digunakan sebagai saklar untuk mengendalikan buzzer.
- **Logic Level Converter Bi-Directional**: Untuk mengonversi level logika antara Arduino Uno (5V) dan modul WiFi ESP8266-ESP01 yang membutuhkan 3.3V.

## Rangkaian Perangkat Keras
### Arduino Uno:
| Komponen       | Koneksi                   |
|----------------|---------------------------|
| 5V             | Bus POS                   |
| GND            | Bus GND                   |

### Sensor Ultrasonik HC-SR04:
| Komponen       | Koneksi                   |
|----------------|---------------------------|
| VCC            | Bus POS                   |
| Trig           | Pin Digital 4 Arduino Uno |
| Echo           | Pin Digital 3 Arduino Uno |
| GND            | Bus GND                   |

### Modul WiFi ESP8266-01:
| Komponen       | Koneksi                   |
|----------------|---------------------------|
| VCC            | Logic Level Converter (LV) |
| RXD            | Logic Level Converter (LV1)|
| TXD            | Logic Level Converter (LV2)|
| GND            | Bus GND                   |

### Logic Level Converter - Bi-Directional:
| Komponen       | Koneksi                           |
|----------------|-----------------------------------|
| LV             | 3.3V Arduino Uno                  |
| LV             | ESP8266-01 CH_PD                  |
| HV             | Bus POS                           |
| HV1            | Pin Digital 11 Arduino Uno|
| HV2            | Pin Digital 10 Arduino Uno|
| GND            | Bus GND                           |

### LCD 16x2 I2C:
| Komponen       | Koneksi                   |
|----------------|---------------------------|
| VCC            | Bus POS                   |
| SDA            | Pin Analog 4 Arduino Uno      |
| SCL            | Pin Analog 5 Arduino Uno      |
| GND            | Bus GND                   |

### Buzzer:
| Komponen       | Koneksi                   |
|----------------|---------------------------|
| POS (+)            | Bus POS                   |
| NEG (-)            | NPN 2N222 Collector       |

### Transistor NPN 2N2222:
| Komponen       | Koneksi                           |
|----------------|-----------------------------------|
| Emitter        | Bus GND                           |
| Base           |  Pin Digital 2 Arduino Uno (Gunakan Resistor 1k Ohm) |

## Langkah-Langkah Penggunaan
### 1. Persiapan Perangkat
- Susun komponen perangkat keras sesuai dengan skema rangkaian yang disediakan.
- Pastikan koneksi sudah benar dan periksa ulang sebelum menyala.
### 2. Konfigurasi Kode Arduino
- Unduh kode sumber dari repositori ini.
- Sesuaikan konfigurasi seperti informasi jaringan WiFi dan token Telegram dalam kode.
- Unggah kode ke Arduino Uno dan Modul ESP8266-01 menggunakan Arduino IDE.
### 3. Persiapan Telegram
- Buat bot di Telegram menggunakan BotFather dan dapatkan token bot yang diperlukan.
- Dapatkan ID chat Anda untuk menerima notifikasi.
### 4. Uji Sistem
- Nyalakan sistem dan pastikan sensor berfungsi dengan baik.
- Pantau ketinggian air dan periksa notifikasi di Telegram saat melebihi batas yang telah ditentukan.

## Kontribusi dan Lisensi
Anda dipersilakan untuk berkontribusi pada pengembangan proyek ini. Gunakan *fork* dari repositori ini, lakukan perubahan, dan ajukan *pull request*. Proyek ini dilisensikan di bawah [lisensi GPL3](https://www.gnu.org/licenses/gpl-3.0.html).

## Kontak
Untuk pertanyaan lebih lanjut, silakan hubungi Andhika Bayu Sena melalui andhikabayusena51@gmail.com.

---
