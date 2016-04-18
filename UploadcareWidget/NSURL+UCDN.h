//
//  NSURL+UCDN.h
//  ExampleProject
//
//  Created by Yury Nechaev on 16.04.16.
//  Copyright © 2016 Uploadcare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSString+UCDN.h"

@interface NSURL (UCDN)

/**
 *  This value determines if the screen scale will be ignored in coordinates and sizes.
 *  Default value is NO.
 */
@property (nonatomic, assign) BOOL ignoreScreenScale;

/**
 *  Instantiates CDN url path with given root host and UUID.
 *
 *  @param root Root host.
 *  @param uuid UUID identifier of the file.
 *
 *  @return Path url.
 */
+ (instancetype)uc_pathWithRoot:(NSString *)root UUID:(NSString *)uuid;

/**
 *  Instantiates CDN path with default root host and UUID.
 *
 *  @param uuid UUID identifier of the file.
 *
 *  @return Path url.
 */
+ (instancetype)uc_pathWithUUID:(NSString *)uuid;

/**
 *  Turn an image to one of the following formats: JPEG or PNG.
 *
 *  @param Format UCDNFormat option.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_format:(UCDNFormat)format;

/**
 *  Image quality affects traffic and page loading speed. Has no effect on non-JPEG images, but does not force format to JPEG.
 *
 *  @param quality UCDNQuality value describing required quality level.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_quality:(UCDNQuality)quality;

/**
 *  Return progressive image. In progressive images data is compressed in multiple passes of progressively higher detail. This is ideal for large images that will be displayed while downloading over a slow connection, allowing a reasonable preview after receiving only a portion of the data. Has no effect on non-JPEG images, but does not force format to JPEG.
 *
 *  @param progressive BOOL value, YES - for progressive, NO - for not.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_progressive:(BOOL)progressive;

/**
 *  Reduces an image proportionally in order to fit it into default limit.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_preview;

/**
 *  Reduces an image proportionally in order to fit it into given dimensions.
 *
 *  @param size Dimensions in pixels.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_preview:(CGSize)size;

/**
 *  Resizes an image to specified dimensions. If only one dimension is specified, and the other one is 0, resizes proportionally to it.
 *
 *  @param size CGSize value describing desired resize value. If one of the values is passed as 0, resize will be proportional.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_resize:(CGSize)size;

/**
 *  Crops an image to specified dimensions. Top left corner is used as offset center.
 *
 *  @discussion If given dimensions are bigger than the original image then the whole image with the rest of the box filled with white color. You can change fill color using setfill method.
 *
 *  @param size CGSize value of crop size in pixels.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_crop:(CGSize)size;

/**
 *  Crops an image to specified dimensions with specified offset.
 *
 *  @discussion If given dimensions are bigger than the original image then the whole image with the rest of the box filled with white color. You can change fill color using setfill method.
 *
 *  @param size   CGSize value of crop size in pixels.
 *  @param center CGPoint value if offset center.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_crop:(CGSize)size center:(CGPoint)center;

/**
 *  Crops an image to specified dimensions. Center of the image is used as offset center.
 *
 *  @discussion If given dimensions are bigger than the original image then the whole image with the rest of the box filled with white color. You can change fill color using setfill method.
 *
 *  @param size CGSize value of crop size in pixels.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_cropToCenter:(CGSize)size;

/**
 *  Scales down an image until one of the dimensions is equals to one of specified then crops the rest. This is really useful if you want to fit as much of image as you can to a box.
 *
 *  @param size CGSize value of crop size in pixels.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_scaleCrop:(CGSize)size;

/**
 *  Scales down an image until one of the dimensions is equals to one of specified then crops the rest. Center of the image is used as offset center. This is really useful if you want to fit as much of image as you can to a box.
 *
 *  @param size CGSize value of crop size in pixels.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_scaleCropToCenter:(CGSize)size;

/**
 *  There is special method stretch which sets behavior of resize, when image is smaller than the given size.
 *
 *  @param mode UCDNStretchMode value describing particular stretch mode.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_stretch:(UCDNStretchMode)mode;

/**
 *  Sets fill color when using crop or convert image with alpha chanel to JPEG.
 *
 *  @param color UIColor object with fill color.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_setFill:(UIColor *)color;

/**
 *  Draws another image on top of current. Most common use case is watermarks. Always applied after all other operations regardless of operations order.
 *
 *  @param uuid                UUID of the overlay image. Overlay image can belong to another project, but must belong to the same account.
 *  @param relativeDimensions  CGSize of the overlay image in pixels. Aspect ratio is always preserved.
 *  @param relativeCoordinates CGPoint position of the overlay image on the current image.
 *  @param opacity             CGFloat opacity of the overlay in percents. You can prepare semitransparent image for overlay, or use opacity parameter.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_overlay:(NSString *)uuid
      relativeDimensions:(CGSize)relativeDimensions
     relativeCoordinates:(CGPoint)relativeCoordinates
                 opacity:(CGFloat)opacity;

/**
 *  Draws another image on top of current. Most common use case is watermarks. Always applied after all other operations regardless of operations order.
 *
 *  @param uuid                UUID of the overlay image. Overlay image can belong to another project, but must belong to the same account.
 *  @param relativeDimensions  CGSize of the overlay image in pixels. Aspect ratio is always preserved.
 *  @param relativeCoordinates CGPoint position of the overlay image on the current image.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_overlay:(NSString *)uuid
      relativeDimensions:(CGSize)relativeDimensions
     relativeCoordinates:(CGPoint)relativeCoordinates;

/**
 *  Draws another image on top of current. Most common use case is watermarks. Always applied after all other operations regardless of operations order.
 *
 *  @param uuid               UUID of the overlay image. Overlay image can belong to another project, but must belong to the same account.
 *  @param relativeDimensions CGSize of the overlay image in pixels. Aspect ratio is always preserved.
 *  @param opacity            CGFloat opacity of the overlay in percents. You can prepare semitransparent image for overlay, or use opacity parameter.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_overlayAtCenter:(NSString *)uuid
              relativeDimensions:(CGSize)relativeDimensions
                         opacity:(CGFloat)opacity;

/**
 *  Draws another image on top of current in the center. Most common use case is watermarks. Always applied after all other operations regardless of operations order.
 *
 *  @param uuid               UUID of the overlay image. Overlay image can belong to another project, but must belong to the same account.
 *  @param relativeDimensions CGSize of the overlay image in pixels. Aspect ratio is always preserved.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_overlayAtCenter:(NSString *)uuid
              relativeDimensions:(CGSize)relativeDimensions;

/**
 *  By default CDN parses image EXIF tags and automatically rotates image according to Orientation tag. BOOL NO allow to turn off this feature.
 *
 *  @param autorotate BOOL NO - disable autorotate based on EXIF data. YES - default.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_autorotate:(BOOL)autorotate;

/**
 *  Performs sharpening on result image. This can be useful after scaling down. Strength can be from 0 to 20. Default is 5.
 *
 *  @param sharp NSUInteger strength of sharpness effect.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_sharp:(NSUInteger)sharp;

/**
 *  Performs Gaussian blur on result image. Strength is standard deviation (aka blur radius) multiplied by ten. Strength can be up to 5000. Default is 10. This filter executes in constant time for different strengths. This means there is no noticeable delay when you are using it with very large radius.
 *
 *  @param blur NSUInteger with blur value.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_blur:(NSUInteger)blur;

/**
 *  Rotates an image to right angle counterclockwise. Angle must be a multiple of 90.
 *
 *  @param angle NSUInteger angle of rotation.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_rotate:(NSUInteger)angle;

/**
 *  Flips image upside-down.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_flip;

/**
 *  Mirrors image.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_mirror;

/**
 *  Applies grayscale filter to the image.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_grayscale;

/**
 *  Inverts image.
 *
 *  @return Formatted path url.
 */
- (NSURL *)uc_invert;

/**
 *  This method is used for adding custom effect in case if API was changed
 *
 *  @param parameter effect string with format key/path
 *
 *  @return Formatted path string
 */
- (NSURL *)uc_addParameter:(NSString *)parameter;

@end
