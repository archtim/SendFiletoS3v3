# SendFiletoS3v3
Simple Visual C++ Console program that uses the AWS C++ SDK to send a file to an S3 bucket.

This code is written in C++ and uses the AWS SDK for C++. The code uploads a file to an S3 bucket on AWS. The first two lines of code are preprocessor directives that link the AWS SDK libraries to the project. The constructor initializes the AWS SDK API and sets the region to “us-east-1”. The destructor shuts down the API when it’s no longer needed. The Send function takes three parameters: bucket_name, file_name, and object_key. It creates an S3 client object and sets up a PutObjectRequest object with the bucket name and object key. It then reads in the file specified by file_name and sets it as the body of the PutObjectRequest object. Finally, it calls PutObject on the S3 client object with the PutObjectRequest object as a parameter to upload the file to S3.
