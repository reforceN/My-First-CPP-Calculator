#include <iostream>
#include <cmath>
#include <iomanip>
// ceil = higer, floor = lower (round)
//using namespace std for cout
//1-something interesting is that you could point the void above everything w/o any code and place the code under everything
//2-so it wont show a error because it already pointed on the code before
//calc list: (+ - * /) (factorial, power, square root) (temperature converter,distance converter, rng, even or odd)
void calc();
void display();
void listfunc();
void celsiusF();
void even();
void rng();
void miles();
int factorial(int firstn);

int main(){
    calc();

    return 0;
}

int factorial(int firstn){
  if(firstn > 1){
     return firstn * factorial(firstn-1);
  }
  else{
    return 1;
  }
}

void calc(){
    while(true){
     char op;
     double firstn;
     double secondn;
     double result;

     display();
     std::cout << "| Enter:  ";
     std::cin >> op;
     std::cout << "|--------------------------|" <<'\n';
      std::cin.clear();
      fflush(stdin);
      
      switch(op){
       case 's':
        std::cout <<"-Square root of: ";
        std::cin >>firstn;
        std::cin.clear();
        fflush(stdin);
        result = sqrt(firstn);
        std::cout << "Square root of "<<firstn<<": ";
        break;
       case 'f':
        std::cout<<"-! of: ";
        std::cin>>firstn;
        std::cin.clear();
        fflush(stdin);
        firstn = factorial(firstn);
        std::cout<<"result: "<<std::fixed<<std::setprecision(0)<<firstn;
        break;
       case 'q':
         listfunc();
         break;
       default:
         std::cout << "-Enter first value: ";
         std::cin >> firstn;
         std::cin.clear();
         fflush(stdin);
         std::cout << "-Enter second value: ";
         std::cin >> secondn;
         std::cin.clear();
         fflush(stdin);
         break;
      }
     switch(op){
        case '+':
          result = firstn + secondn;
          break;
        case '-':
           result = firstn - secondn;
           break;
        case '*':
            result = firstn * secondn;
            break;
        case '/':
            result = firstn / secondn;
            break;
        case 'p':
            result = round(std::pow(firstn, secondn));
            break;
        case 's':break;
        case 'f':break;
        case 'q':break;
        default:
        std::cout << "Invalid operator or value, op: "<<op<<", and first and second value = "<<firstn<<", "<<secondn<<' '<<'\n';
    }
     if(op=='/'){
        std::cout << "{The result is " << std::fixed<<result <<"}"<< '\n'; 
    }
     else if(op == 'f' || op == 'q'){
      std::cout<<'\n';
     }
      else{
        std::cout << "{The result is " <<std::fixed<<std::setprecision(0)<< result <<"}"<< '\n'; 
    }}

}
void display(){
  using namespace std;
   cout<<"----------------------------"<<'\n';//1
   cout<<"|       Calculator         |"<<'\n';//2
   cout<<"|(+ - / *)                 |"<<'\n';//3
   cout<<"|(f for !)                 |"<<'\n';//4
   cout<<"|(p for power)             |"<<'\n';//5
   cout<<"|(q for program list)      |"<<'\n';//6
   cout<<"|                          |"<<'\n';//7
   cout<<"|--------------------------|"<<'\n';//8
}
void listfunc(){
  int input;
  std::cout<<"------------Programs list-------------\n";
  std::cout<<"|1 - Temperature Converter           |"<<'\n';
  std::cout<<"|2 - Distance Converter              | "<<'\n';
  std::cout<<"|3 - RNG                             |"<<'\n';
  std::cout<<"|4 - Even or Odd                     |"<<'\n';
  std::cout<<"|5 - Leave                           |"<<'\n';
  std::cout<<"| Enter: ";

  std::cin>>input;
  std::cin.clear();
      fflush(stdin);

  switch(input){
  case 1:
    celsiusF();
    break;
  case 2:
     miles();
     break;
  case 3:
     rng();
     break;
  case 4:
   even();
   break;
  case 5:break;
  default:
    std::cout<<"Did not select a proper program, returning to calculator..\n";
    break;
  }
}

void celsiusF(){
   char unit;
    double temp;

    std::cout<<"\n---------------------------\nTemprature conversion program\n"<<"-C for celsius, and F for fahrenheit, K for kelvin: ";
    std::cin>>unit;

    if(unit == 'C' || unit == 'c'){
         std::cout<<"Enter the temperature in celsius: ";
         std::cin>>temp;
         temp = (1.8 * temp) + 32;
         std::cout<<"The temperature in fahrenheit is "<<temp<<'\n';}
    else if(unit == 'F'||unit == 'f'){
        std::cout<<"Enter the temperature in fahrenheit: ";
        std::cin>>temp;
        temp = (temp - 32) / 1.8;
        std::cout<<"The temperature in celsius is "<<std::fixed<<std::setprecision(1)<<temp<<'\n';}
    else if(unit == 'K'||unit =='k'){
         std::cout<<"Enter the temperature in celsius: ";
         std::cin>>temp;
         temp = temp + 273;
         std::cout<<"The temperature in kelvin is "<<temp<<'\n';}
    else{
        std::cout<<"Enter a valid unit";
    }
}

void even(){
    int user;

    std::cout<<'\n'<<"-Enter a number: ";
    std::cin>>user;
 
    if(user % 2 == 0 ){
        std::cout<<"Even";
    }
    else{
        std::cout<<"Odd";
    }}

void rng(){
  srand(time(0));
  int input_number;
  std::cout<<"RNG from 1 to ";
  std::cin>>input_number;
  int number = (rand() % input_number) + 1;
  std::cout<<"Number from 1 to "<<input_number<<" is: "<<number;

}

void miles(){
  double distance;
  char measure1;
  char measure2;
  double result;
  std::string defmea2;

  std::cout<<"-------------------------------------------------\n";
  std::cout<<"You have the distance in?\n (K for Kilometers)\n (M for meters)\n (C for Centimeters)\n (m for milimeters)\n"<<"- ";
  std::cin>>measure1;
   std::cin.clear();
   fflush(stdin);
  std::cout<<"Want to convert to?\n (K for Kilometers)\n (M for meters)\n (C for Centimeters)\n (m for milimeters)\n"<<"- ";
  std::cin>>measure2;
   std::cin.clear();
   fflush(stdin);
  std::cout<<"-Enter value: ";
  std::cin>>distance;
   std::cin.clear();
   fflush(stdin);
  //the else if chain of despair and doom.
  if(measure1 == 'K' && measure2 == 'M'){result = distance*1000;}
  else if(measure1 == 'K' && measure2 == 'C'){result = distance*100000;}
  else if(measure1 == 'K' && measure2 == 'm'){result = distance*1000000;}
  else if(measure1 == 'M' && measure2 == 'K'){result = distance/1000;}
  else if(measure1 == 'M' && measure2 == 'C'){result = distance*100;}
  else if(measure1 == 'M' && measure2 == 'm'){result = distance/1000;}
  else if(measure1 == 'C' && measure2 == 'm'){result = distance*10;}
  else if(measure1 == 'C' && measure2 == 'K'){result = distance/100000;}
  else if(measure1 == 'C' && measure2 == 'M'){result = distance/100;}
  else if(measure1 == 'm' && measure2 == 'K'){result = distance*1000000;}
  else if(measure1 == 'm' && measure2 == 'C'){result = distance/10;}
  else if(measure1 == 'm' && measure2 == 'M'){result = distance/1000;}
  switch(measure2){
    case 'K':
     defmea2 = "Kilometers";
     break;
    case 'M':
     defmea2 = "Meters";
     break;
    case 'C':
     defmea2 = "Centimeters";
     break;
    case 'm':
     defmea2 = "Milimeters";
     break;
    default: 
     std::cout<<"idk bro";
     break;
  }
  if(result <1){
    std::cout<<"\nresult is "<<std::fixed<<std::setprecision(7)<<result<<" "<<defmea2<<'\n';}
  else{std::cout<<"\nresult is "<<std::fixed<<std::setprecision(0)<<result<<" "<<defmea2<<'\n';}
 }