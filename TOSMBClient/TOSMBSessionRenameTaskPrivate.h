//
//  TOSMBSessionRenameTaskPrivate.h
//  TOSMBClient
//
//  Created by Demian Steelstone on 13.01.17.
//  Copyright © 2017 TimOliver. All rights reserved.
//

#ifndef TOSMBSessionRenameTaskPrivate_h
#define TOSMBSessionRenameTaskPrivate_h

#import "TOSMBSessionRenameTask.h"
#import "TOSMBSessionMoveTaskPrivate.h"

@interface TOSMBSessionRenameTask () <TOSMBSessionConcreteTask>

- (instancetype)initWithSession:(TOSMBSession *)session
                     sourcePath:(NSString *)srcPath
                        newName:(NSString *)newName
                       delegate:(id<TOSMBSessionUploadTaskDelegate>)delegate;

- (instancetype)initWithSession:(TOSMBSession *)session
                     sourcePath:(NSString *)srcPath
                        newName:(NSString *)newName
                 successHandler:(TOSMBSessionUploadTaskSuccessBlock)successHandler
                    failHandler:(TOSMBSessionTaskFailBlock)failHandler;

@end
#endif /* TOSMBSessionRenameTaskPrivate_h */
