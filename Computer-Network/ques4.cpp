// // /*
// //   Selective repeat sliding window protocol
// // */

// // #include <iostream>
// // #include <cstdlib>
// // #include <ctime>
// // #include <cmath>
// // using namespace std;

// // #define TOT_FRAMES 500
// // #define FRAMES_SEND 10

// // class sel_repeat
// // {
// // private:
// //     int fr_send_at_instance;
// //     int arr[TOT_FRAMES];
// //     int send[FRAMES_SEND];
// //     int rcvd[FRAMES_SEND];
// //     char rcvd_ack[FRAMES_SEND];
// //     int sw;
// //     int rw; //tells expected frame

// // public:
// //     void input();
// //     void sender(int);
// //     void receiver(int);
// // };

// // void sel_repeat::input()
// // {

// //     int n; //no. of bits for the frame
// //     int m; //no. of frames from n bits
// //     int i;
// //     cout << "\nEnter the no. of bits for the sequence no. : ";
// //     cin >> n;
// //     m = pow(2, n);

// //     int t = 0;

// //     fr_send_at_instance = (m / 2);

// //     for (i = 0; i < TOT_FRAMES; i++)

// //     {

// //         arr[i] = t;

// //         t = (t + 1) % m;
// //     }

// //     for (i = 0; i < fr_send_at_instance; i++)

// //     {

// //         send[i] = arr[i];

// //         rcvd[i] = arr[i];

// //         rcvd_ack[i] = 'n';
// //     }

// //     rw = sw = fr_send_at_instance;

// //     sender(m);
// // }

// // void sel_repeat::sender(int m)

// // {

// //     for (int i = 0; i < fr_send_at_instance; i++)

// //     {

// //         if (rcvd_ack[i] == 'n')

// //             cout << "\nSENDER : Frame " << send[i] << " is sent\n";
// //     }

// //     receiver(m);
// // }

// // void sel_repeat::receiver(int m)

// // {

// //     time_t t;

// //     int f;
// //     int j;
// //     int f1;

// //     int a1;

// //     char ch;

// //     srand((unsigned)time(&t));

// //     for (int i = 0; i < fr_send_at_instance; i++)

// //     {

// //         if (rcvd_ack[i] == 'n')

// //         {

// //             f = rand() % 10;

// //             //if f=5 frame is discarded for some reason

// //             //else frame is correctly recieved

// //             if (f != 5)

// //             {

// //                 for (int j = 0; j < fr_send_at_instance; j++)

// //                     if (rcvd[j] == send[i])

// //                     {

// //                         cout << "\nreciever:Frame " << rcvd[j] << "recieved correctly\n";

// //                         rcvd[j] = arr[rw];

// //                         rw = (rw + 1) % m;

// //                         break;
// //                     }
// //                 int j;
// //                 if (j == fr_send_at_instance)

// //                     cout << "\nreciever:Duplicate frame " << send[i] << " discarded\n";

// //                 a1 = rand() % 5;

// //                 //if al==3 then ack is lost

// //                 //else recieved

// //                 if (a1 == 3)

// //                 {

// //                     cout << "\n(acknowledgement " << send[i] << " lost)\n";

// //                     cout << "\n(sender timeouts-->Resend the frame)\n";

// //                     rcvd_ack[i] = 'n';
// //                 }

// //                 else

// //                 {

// //                     cout << "(acknowledgement " << send[i] << " recieved)\n";

// //                     rcvd_ack[i] = 'p';
// //                 }
// //             }

// //             else

// //             {
// //                 int ld = rand() % 2;

// //                 //if =0 then frame damaged

// //                 //else frame lost

// //                 if (ld == 0)

// //                 {

// //                     cout << "\nRECEIVER : Frame " << send[i] << " is damaged\n";

// //                     cout << "\nRECEIVER : Negative Acknowledgement " << send[i] << " sent\n";
// //                 }

// //                 else

// //                 {

// //                     cout << "\nRECEIVER : Frame " << send[i] << " is lost\n";

// //                     cout << "\n (SENDER TIMEOUTS-->RESEND THE FRAME)\n";
// //                 }

// //                 rcvd_ack[i] = 'n';
// //             }
// //         }
// //     }

// //     for (int j = 0; j < fr_send_at_instance; j++)

// //     {

// //         if (rcvd_ack[j] == 'n')
// //             break;
// //     }

// //     int i = 0;

// //     for (int k = j; k < fr_send_at_instance; k++)
// //     {

// //         send[i] = send[k];
// //         if (rcvd_ack[k] == 'n')
// //             rcvd_ack[i] = 'n';
// //         else
// //             rcvd_ack[i] = 'p';
// //         i++;
// //     }

// //     if (i != fr_send_at_instance)
// //     {
// //         for (int k = i; k < fr_send_at_instance; k++)
// //         {
// //             send[k] = arr[sw];
// //             sw = (sw + 1) % m;
// //             rcvd_ack[k] = 'n';
// //         }
// //     }
// //     cout << "\nWant to continue('Y' or 'y' to continue): ";
// //     cin >> ch;
// //     cout << "\n";
// //     if (ch == 'y')
// //         sender(m);
// //     else
// //         exit(0);
// // }

// // int main()
// // {
// //     sel_repeat sr;
// //     ;
// //     sr.input();

// //     return 0;
// // }

// #include <iostream>
// using namespace std;
// // #include <conio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <math.h>

// #define TOT_FRAMES 500

// #define FRAMES_SEND 10

// class sel_repeat

// {

// private:
//     int fr_send_at_instance;
//     int arr[TOT_FRAMES];
//     int send[FRAMES_SEND];
//     int rcvd[FRAMES_SEND];
//     char rcvd_ack[FRAMES_SEND];
//     int sw;
//     int rw; //tells expected frame

// public:
//     void input();
//     void sender(int);
//     void receiver(int);
// };

// void sel_repeat::input()

// {

//     int n; //no. of bits for the frame
//     int m; //no. of frames from n bits
//     int i;
//     cout << "Enter the no. of bits for the sequence no. : ";
//     cin >> n;
//     m = pow(2, n);
//     int t = 0;
//     fr_send_at_instance = (m / 2);

//     for (i = 0; i < TOT_FRAMES; i++)

//     {

//         arr[i] = t;
//         t = (t + 1) % m;
//     }

//     for (i = 0; i < fr_send_at_instance; i++)

//     {

//         send[i] = arr[i];

//         rcvd[i] = arr[i];

//         rcvd_ack[i] = 'n';
//     }

//     rw = sw = fr_send_at_instance;
//     sender(m);
// }

// void sel_repeat::sender(int m)

// {

//     for (int i = 0; i < fr_send_at_instance; i++)

//     {

//         if (rcvd_ack[i] == 'n')

//             cout << "SENDER : Frame " << send[i] << " is sent\n";
//     }

//     receiver(m);
// }

// void sel_repeat::receiver(int m)

// {

//     time_t t;
//     int f;
//     int j;
//     int f1;
//     int a1;
//     char ch;
//     srand((unsigned)time(&t));
//     for (int i = 0; i < fr_send_at_instance; i++)

//     {

//         if (rcvd_ack[i] == 'n')

//         {

//             f = rand() % 10;
//             //if f=5 frame is discarded for some reason

//             //else frame is correctly recieved
//             if (f != 5)
//             {

//                 for (int j = 0; j < fr_send_at_instance; j++)
//                     if (rcvd[j] == send[i])
//                     {

//                         cout << "reciever:Frame" << rcvd[j] << "recieved correctly\n";
//                         rcvd[j] = arr[rw];
//                         rw = (rw + 1) % m;
//                         break;
//                     }

//                 int j;
//                 if (j == fr_send_at_instance)
//                     cout << "reciever:Duplicate frame" << send[i] << "discarded\n";
//                 a1 = rand() % 5; //if al==3 then ack is lost
//                 //else recieved
//                 if (a1 == 3)
//                 {

//                     cout << "(acknowledgement " << send[i] << " lost)\n";
//                     cout << "(sender timeouts-->Resend the frame)\n";
//                     rcvd_ack[i] = 'n';
//                 }

//                 else

//                 {

//                     cout << "(acknowledgement " << send[i] << " recieved)\n";
//                     rcvd_ack[i] = 'p';
//                 }
//             }

//             else

//             {
//                 int ld = rand() % 2; //if =0 then frame damaged

//                 //else frame lost
//                 if (ld == 0)
//                 {
//                     cout << "RECEIVER : Frame " << send[i] << " is damaged\n";
//                     cout << "RECEIVER : Negative Acknowledgement " << send[i] << "sent\n "; 
//                 }

//                 else

//                 {

//                     cout << "RECEIVER : Frame " << send[i] << " is lost\n";
//                     cout << "(SENDER TIMEOUTS-->RESEND THE FRAME)\n";
//                 }

//                 rcvd_ack[i] = 'n';
//             }
//         }
//     }

//     for (int j = 0; j < fr_send_at_instance; j++)

//     {
//         if (rcvd_ack[j] == 'n')
//             break;
//     }

//     int i = 0;

//     for (int k = j; k < fr_send_at_instance; k++)

//     {

//         send[i] = send[k];
//         if (rcvd_ack[k] == 'n')
//             rcvd_ack[i] = 'n';
//         else
//             rcvd_ack[i] = 'p';
//         i++;
//     }

//     if (i != fr_send_at_instance)

//     {

//         for (int k = i; k < fr_send_at_instance; k++)

//         {

//             send[k] = arr[sw];
//             sw = (sw + 1) % m;
//             rcvd_ack[k] = 'n';
//         }
//     }

//     cout << "Want to continue";
//     cin >> ch;
//     cout << "\n";

//     if (ch == 'y')
//         sender(m);
//     else
//         exit(0);
// }

// int main()

// {

//     sel_repeat sr;
//     sr.input();
// }

//WAP to implement selective repeat sliding window.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

 vector<int> v;
int protocol(int nf,int N)
{
    int no_tr=0;
    int i=0;
    while(i<nf)
    {
        int x=0;
        for(int j=i;j<i+N && j<nf;j++)
        {
            cout<<"Sent Frame "<<j<<endl;
            no_tr++;
        }
        for(int j=i;j<i+N && j<nf;j++)
        {
            int flag = rand()%2;
            if(!flag)
            {
                cout<<"Acknowledgment for Frame "<<j<<endl;
                x++;
            }
        else
            {
                cout<<"Frame "<<j<<" Not Received"<<endl;
                v.push_back(j);
                x++;
            }
        }
        cout<<endl;
        i+=x;
    }
    return no_tr;
}

void sendRemaining(int &no_tr,int N)
{
    int i=0,nf=v.size();
    while(i<nf)
    {
        for(int j=i;j<v.size()&&j<i+N;j++)
        {
            cout<<"Sent Frame "<<v[j]<<endl;
            no_tr++;
        }   
        for(int j=i;j<v.size()&&j<i+N;j++)
        {
            int flag = rand()%2;
            if(!flag)
            {
                cout<<"Acknowledgment for Frame "<<v[j]<<endl;
                v[j]=-999;
            }
            else
            {
                cout<<"Frame "<<v[j]<<" Not Received"<<endl;
            }
        }
        cout<<endl;
        i+=N;
    }
    auto it=remove_if(v.begin(),v.end(),[](const int j){return j<0;});
    v.erase(it,v.end());
}

int main()
{
    int nf,N,no_tr;
    char choice;
    srand(time(NULL));
    cout<<"Enter the number of frames : ";
    cin>>nf;
    cout<<"Enter the Window Size : ";
    cin>>N;
    no_tr=protocol(nf,N);
    while(v.size()>0)
    {
        cout<<"Do you want to retransmitt remaining frames? Enter 'Y' or 'y' for yes"<<endl;
        cin>>choice;
        if(choice=='Y'||choice=='y')
        {
            sendRemaining(no_tr,N);
        }
        else
            break;
    }
    cout<<"Total number of transmissions : "<<no_tr<<endl;
    return 0;
}