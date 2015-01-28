//
//  LDCFoundationCameraViewPlugin.m
//  InstaGraacCamera2
//
//  Created by Paulo Miguel Almeida on 1/27/15.
//  Copyright (c) 2015 Loducca Publicidade. All rights reserved.
//

#import "LDCFoundationCameraViewPlugin.h"

@interface LDCFoundationCameraViewPlugin()

@end

@implementation LDCFoundationCameraViewPlugin

-(CDVPlugin *)initWithWebView:(UIWebView *)theWebView{
    self = (LDCFoundationCameraViewPlugin*)[super initWithWebView:theWebView];
    return self;
}

-(void)createCameraView:(CDVInvokedUrlCommand *) command
{
    /**
        Method largely based on devgeeks example of how to add a native view from a cordova plugin.
        https://github.com/devgeeks/VolumeSlider
     */
    
    NSArray* arguments = [command arguments];
    
    NSUInteger argc = [arguments count];
    
    if (argc < 4) { // at a minimum we need x origin, y origin and width...
        return;
    }
    
    if (self.cameraView && self.footerView) {
        return;  //already created, don't need to create it again
    }
    
    CGFloat originx,originy,width,height;
    
    originx = [[arguments objectAtIndex:0] floatValue];
    originy = [[arguments objectAtIndex:1] floatValue];
    width = [[arguments objectAtIndex:2] floatValue];
    height = [[arguments objectAtIndex:3] floatValue];

    CGRect cameraViewRect = CGRectMake(originx,originy,width,height);
    CGRect cameraFooterRect = CGRectMake(
                                         originx,
                                         height - 132,
                                         width,
                                         132
                                         );
    
    //Creating LDCFoundationCameraView instance
    self.cameraView = [[LDCFoundationCameraView alloc] initWithFrame:cameraViewRect];
    self.cameraView.backgroundColor = [UIColor blackColor];

    //Creating LDCFoundationCameraFooterView instance
    self.footerView = [[LDCFoundationCameraFooterView alloc] initWithFrame:cameraFooterRect];

    //Adding 'em to webview
    [self.webView.superview addSubview:self.cameraView];
    [self.webView.superview addSubview:self.footerView];
    
    //Initializing AVFoundation
    [self.cameraView initializeCamera];
    
}


@end