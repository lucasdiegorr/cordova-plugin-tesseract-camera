//
//  LDCTesseractCameraRectDetectionViewController.h
//
//  Version 0.0.1
//
//  The MIT License (MIT)
//
//  Original work Copyright (c) 2015 Maximilian Mackh <mmackh@gmail.com>
//  Modified work Copyright (c) 2015 Paulo Miguel Almeida Rodenas <paulo.ubuntu@gmail.com>
//
//  Get the latest version from here:
//
//  https://github.com/mmackh/IPDFCameraViewController
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

//Libraries
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreMedia/CoreMedia.h>
#import <CoreVideo/CoreVideo.h>
#import <CoreImage/CoreImage.h>
#import <ImageIO/ImageIO.h>
#import <GLKit/GLKit.h>

//Categories
#import "UIImage+Base64.h"

//typedef NS_ENUM(NSInteger,IPDFCameraViewType)
//{
//    IPDFCameraViewTypeBlackAndWhite,
//    IPDFCameraViewTypeNormal
//};

@protocol LDCTesseractCameraRectDetectionViewControllerDelegate <NSObject>

-(void) snapStillImageHasBeenTaken:(UIImage*) image;
-(void) closeButtonHasBeenTouched; // Yet to be implemented
@end

@interface LDCTesseractCameraRectDetectionViewController : UIViewController<AVCaptureVideoDataOutputSampleBufferDelegate>

@property (nonatomic, retain) id<LDCTesseractCameraRectDetectionViewControllerDelegate> delegate;
@end