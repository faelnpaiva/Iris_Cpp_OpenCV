#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"
#include <math.h>
#include <stdio.h>
#include "variables.h"
#include "create_gabor.h"






using namespace cv;



	

	
//////////////////////////////////////////
///               VERSION 1            ///
///         WEB MATLAB VERSION         ///
///           USING BANDWIDTH          ///
//////////////////////////////////////////
void Gabor:: create_gabor_kernel_v1( float sig, float thet, float lm, float gamma , float ps , float bw){

   

    float    sigma=sig ;
    float    lmbda=lm ;
    float    slratio;
	float    N;
	int      kernel_size;
   

	slratio = (1/CV_PI)*sqrt(log(2.0)/2)*( (pow(2,bw)+1) /(pow(2,bw)-1));

	if  (sigma == 0)
  sigma  = slratio * lmbda;
   else if (lmbda == 0)
  lmbda = sigma / slratio;


    float    theta = (thet*CV_PI/180);
    float    psi   = (ps  *CV_PI/180);    

      int      x = 0;
      int      y = 0;
      float    X = 0;
      float    Y = 0;
      

	  if (gamma <= 1 && gamma > 0)

    N = cvRound(2.5*sigma/gamma);  //sigma/gamma = 1.6 so N=4
	  else
    N = cvRound(2.5*sigma);
   
		

kernel_size = (int)(2*N+1);


kernel_real =cvCreateMat(kernel_size,kernel_size, CV_32FC1);
 kernel_imag =cvCreateMat(kernel_size,kernel_size, CV_32FC1);
 kernel_mag  =cvCreateMat(kernel_size,kernel_size, CV_32FC1);

     


      float    X2,Y2;
      float    sigma2;
      float    gamma2;
      float    F;

      float    real = 0;
      float    imag = 0;
      float    mag  = 0;
      

      float    K;
      float    temp1;
      float    temp2;
      float    temp3;

      

  int   kernel_mid    = (int) (kernel_size-1)/2;     //kernel anchor


     sigma2=  sigma*sigma;
     gamma2=  gamma*gamma;

	 K    = (    1/(2*(CV_PI)*sigma2) );
     F    = (2*CV_PI )/(float) lmbda ;          // Frequency


	printf("Sigma = %f ; Lmbda = %f , kernel_size = %d ",sigma,lmbda,kernel_size);


 for(int i=0;i<kernel_size;i++){   //row

      for(int j=0;j<kernel_size;j++){  //col


          x = j-(kernel_mid);        //col
          y = i-(kernel_mid);        //row


       
         //temp1 = (pow(K,2.0)/pow(Sigma,2.0))*exp(-(pow((double)x,2.0)+pow((double)y,2.0))*pow(K,2.0)/(2.0*pow(Sigma,2.0)));

         // temp2 = cos(   K*cos(Phi*(CV_PI/180))*x +  K*sin(Phi*(CV_PI/180))*y  );              //Re (s(x, y)) = cos (2PI(u0 x + v0 y) + P)
         // temp3 = sin(   K*cos(Phi*(CV_PI/180))*x +  K*sin(Phi*(CV_PI/180))*y  );              //Im (s(x, y)) = sin (2PI(u0 x + v0 y) + P)
 


          X =    (x*cos(theta))   + ( y*sin(theta))  ;
          Y =    (-x*sin(theta))  + ( y*cos(theta))  ;
 

     Y2    =  Y*Y;
     X2    =  X*X;
     

    temp1=K*exp( -0.5* (  (X2+(Y2*gamma2)) / (sigma2) )  );  //checked

	temp2= cos(  ((X*F)+ psi)  );     //checked

    temp3= sin(  ((X*F)+ psi)  );




          real = (temp1*temp2);                         //checked
          imag = (temp1*temp3);

          mag  = ((real*real)+(imag*imag));


       //  printf ( "x: %d , y: %d  ,real:%2f\n",x,y,real);

              //gan_mat_set_el(pmReal, i, j, dReal);
              //cvmSet( (CvMat*)mReal, i, j, dReal );

                cvSetReal2D((CvMat*)kernel_real, i, j, real );   // NOTE : REMEMBER TO CHANGE
                cvSetReal2D((CvMat*)kernel_imag, i, j, imag );
                cvSetReal2D((CvMat*)kernel_mag , i, j,mag  );


      }}

  

 //cvNormalize(kernel_real,kernel_real,1,0,CV_C,NULL);



//cvScale(kernel_real,kernel_real,0.5);
//cvAddS(kernel_real,cvScalar(0.5),kernel_real,NULL);

//cvShowImage("Kernel_real",kernel_real);
//cvShowImage("Kernel_imag",kernel_imag);
//cvShowImage("Kernenl_magnitude",kernel_mag);



 //Lkernel =cvCreateMat(kernel_size*10, kernel_size*10, CV_32FC1);
//cv::resize(kernel_real, Lkernel, Lkernel.size());
//Lkernel /= 2.;
//Lkernel += 0.5;
 // cv::imshow("kernel",Lkernel);


}


















