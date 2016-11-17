//
//  ViewController.h
//  TOSMBClientExample
//
//  Created by Tim Oliver on 7/27/15.
//  Copyright (c) 2015 TimOliver. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "TORootViewController.h"

@interface TORootTableViewController : UITableViewController

@property (nonatomic, weak, nullable) TORootViewController *rootController;
@property (nonatomic, strong, null_resettable) TOSMBSession *session;

@end
