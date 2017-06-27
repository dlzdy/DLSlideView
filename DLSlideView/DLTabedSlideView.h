//  标签条目
//  DLTabedSlideView.h
//  DLSlideController
//
//  Created by Dongle Su on 14-12-8.
//  Copyright (c) 2014年 dongle. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DLSlideTabbarProtocol.h"

//========== DLTabedbarItem ==============//
@interface DLTabedbarItem : NSObject
// 标签标题
@property (nonatomic, strong) NSString *title;
// 标签图标
@property(nonatomic, strong) UIImage *image;
// 标签选中图片
@property(nonatomic, strong) UIImage *selectedImage;

+ (DLTabedbarItem *)itemWithTitle:(NSString *)title image:(UIImage *)image selectedImage:(UIImage *)selectedImage;
@end


@class DLTabedSlideView;


//========== DLTabedSlideViewDelegate ==============//
@protocol DLTabedSlideViewDelegate <NSObject>
/**
 * 标签数量
 */
- (NSInteger)numberOfTabsInDLTabedSlideView:(DLTabedSlideView *)sender;

/**
 * 选中标签索引返回视图
 */
- (UIViewController *)DLTabedSlideView:(DLTabedSlideView *)sender controllerAt:(NSInteger)index;

/**
 * 释放标签选中
 */
@optional
- (void)DLTabedSlideView:(DLTabedSlideView *)sender didSelectedAt:(NSInteger)index;
@end


//========== DLTabedSlideView ==============//
@interface DLTabedSlideView : UIView<DLSlideTabbarDelegate>
//@property(nonatomic, strong) NSArray *viewControllers;
@property(nonatomic, weak) UIViewController *baseViewController;
@property(nonatomic, assign) NSInteger selectedIndex;
//set tabbar properties.
@property (nonatomic, strong) UIColor *tabItemNormalColor;
@property (nonatomic, strong) UIColor *tabItemSelectedColor;
@property(nonatomic, strong) UIImage *tabbarBackgroundImage;
@property(nonatomic, strong) UIColor *tabbarTrackColor;
@property(nonatomic, strong) NSArray *tabbarItems;
@property(nonatomic, assign) float tabbarHeight;
@property(nonatomic, assign) float tabbarBottomSpacing;
// cache properties
@property(nonatomic, assign) NSInteger cacheCount;
- (void)buildTabbar;
//@property(nonatomic, strong) IBOutlet id<DLSlideTabbarProtocol> tabarView;
@property(nonatomic, weak)IBOutlet id<DLTabedSlideViewDelegate>delegate;
@end
