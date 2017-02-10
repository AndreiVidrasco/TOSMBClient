//
// TOSMBDownloadTask.h
// Copyright 2015-2016 Timothy Oliver
//
// This file is dual-licensed under both the MIT License, and the LGPL v2.1 License.
//
// -------------------------------------------------------------------------------
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// -------------------------------------------------------------------------------

#import "TOSMBSessionTask.h"
#import "TOSMBConstants.h"

@class TOSMBSession;
@class TOSMBSessionDownloadTask;

typedef void(^TOSMBSessionDownloadTaskSuccsessBlock)(NSString *path);

@protocol TOSMBSessionDownloadTaskDelegate <TOSMBSessionTaskDelegate>

@optional

/**
 Delegate event that is called when the file has successfully completed downloading and was moved to its final destionation.
 If there was a file with the same name in the destination, the name of this file will be modified and this will be reflected in the
 `destinationPath` value
 
 @param downloadTask The download task object calling this delegate method.
 @param destinationPath The absolute file path to the file.
 */
- (void)downloadTask:(TOSMBSessionDownloadTask *)downloadTask didFinishDownloadingToPath:(NSString *)destinationPath;

/**
 Delegate event that is called periodically as the download progresses, updating the delegate with the amount of data that has been downloaded.
 
 @param downloadTask The download task object calling this delegate method.
 @param bytesWritten The number of bytes written in this particular iteration
 @param totalBytesWrite The total number of bytes written to disk so far
 @param totalBytesTowWrite The expected number of bytes encompassing this entire file
 */
- (void)downloadTask:(TOSMBSessionDownloadTask *)downloadTask
       didWriteBytes:(uint64_t)bytesWritten
  totalBytesReceived:(uint64_t)totalBytesReceived
totalBytesExpectedToReceive:(int64_t)totalBytesToReceive;

/**
 Delegate event that is called when the file did not successfully complete.
 
 @param downloadTask The download task object calling this delegate method.
 @param error The error describing why the task failed.
 */
- (void)downloadTask:(TOSMBSessionDownloadTask *)downloadTask didCompleteWithError:(NSError *)error __deprecated_msg("See -task:didCompleteWithError:");

@end

@interface TOSMBSessionDownloadTask : TOSMBSessionTask

/** The target file path that the file will be downloaded to. */
@property (readonly) NSString *destinationFilePath;

@end
