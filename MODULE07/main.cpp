#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

// Función para convertir una cadena hexadecimal a un vector de bytes
std::vector<unsigned char> hexToBytes(const std::string& hex) {
    std::vector<unsigned char> bytes;
    for (unsigned int i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        unsigned char byte = (unsigned char) strtol(byteString.c_str(), nullptr, 16);
        bytes.push_back(byte);
    }
    return bytes;
}

// Función para codificar en base64
std::string base64Encode(const std::vector<unsigned char>& bytes) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;
    
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);
    
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); // No newlines
    BIO_write(bio, bytes.data(), bytes.size());
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    
    std::string base64String(bufferPtr->data, bufferPtr->length);
    BIO_free_all(bio);
    
    return base64String;
}

int main() {
    std::string hexString = "16D85ACC441674FBA2DF65190663F43A243E8FA5424E49143B520D3DF8AF68036E47"
                            "114F20A16827E1B16612137E59ECD492E468BC6CD109F65388DC57A58E8942585C8"
                            "D193B96732206"
                            "9";
    
    std::vector<unsigned char> bytes = hexToBytes(hexString);
    std::cout << "Bytes: " << bytes << std::endl;
    std::string base64String = base64Encode(bytes);
    
    std::cout << "Base64: " << base64String << std::endl;
    
    return 0;
}