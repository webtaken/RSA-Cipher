#include "functions.h"

class RSA{
  int e , d , n;
public:
  RSA(){
    generate_sieve();
    srand(time(NULL));
    //int p = get_random_prime(rand() % 50 + 1);
    //int q = get_random_prime(rand() % 50 + 1);
    int p = 53 , q = 137;
    while(q == p){
      q = get_random_prime(rand() % 1229 + 1);
    }
    n = p * q ;
    int phi_n = (p - 1) * (q - 1);//por la prpiedad
    /*do{   
      e = rand()% (phi_n - 2) + 2;// 1 < e < phi_n
    }while(GCD(phi_n , e) != 1);
    */
    e = 1865;
    d = modular_inverse(e , phi_n);    
  }
  
  RSA(int e_c , int n_c){
    n = n_c;
    e = e_c;
  }
  
  vector <int> cifrado(string msg){
    vector <int> cifer(msg.size());
    for(int i = 0; i < msg.size(); i++){
      cifer[i] = expo(find(msg[i]) , e , n);
    }
    return cifer;
  }
  
  string descifrar(vector <int> msg){
    string des = "";
    for(int i = 0; i < msg.size(); i++){
      des += alphabet[expo(msg[i] , d , n)];
    }
    return des;
  }
  
  int get_public_key(){
    return e;
  }
  
  int get_n(){
    return n;
  }
  
  int get_secret_key(){
    return d;
  }
   
};

int main(){
  RSA guido(3337 , 3827);
  RSA alexandra(15725 , 40633);
  RSA alonsillo(85 , 3569);
  RSA jose(19169 , 64516997);
  RSA yo;
  cout << "e: " << yo.get_public_key() << " n: " << yo.get_n() << endl;
  vector <int> msg_a_descifrar(8);
  //6121 7038 7000 5992 654 5705 5992 4027 7000
  msg_a_descifrar[0] = 6000;
  msg_a_descifrar[1] = 292;
  msg_a_descifrar[2] = 5900;
  msg_a_descifrar[3] = 7261;
  msg_a_descifrar[4] = 654;
  msg_a_descifrar[5] = 5705;
  msg_a_descifrar[6] = 5992;
  msg_a_descifrar[7] = 4027;
  string msg = yo.descifrar(msg_a_descifrar);
  cout << msg << endl;
  vector <int> cipher = guido.cifrado("hola");
  for(int i = 0; i < cipher.size(); i++){
    cout << cipher[i] << " ";
  }
  cout << endl;
  cipher = alexandra.cifrado("hola");
  for(int i = 0; i < cipher.size(); i++){
    cout << cipher[i] << " ";
  }
  cout << endl;
  
  cipher = alonsillo.cifrado("(");
  for(int i = 0; i < cipher.size(); i++){
    cout << cipher[i] << " ";
  }
  cout << endl;

  
  cipher = jose.cifrado("josesillo");
  for(int i = 0; i < cipher.size(); i++){
    cout << cipher[i] << " ";
  }
  cout << endl;
  return 0;
}
