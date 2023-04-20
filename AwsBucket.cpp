#include "AwsBucket.h"

#pragma comment(lib, "aws-cpp-sdk-core.lib")
#pragma comment(lib, "aws-cpp-sdk-s3.lib")

CAwsBucket::CAwsBucket() {
    // constructor implementation

    Aws::InitAPI(options);

    config.region = "us-east-1";
}

CAwsBucket::~CAwsBucket() {
    // destructor implementation
    Aws::ShutdownAPI(options);
}

int CAwsBucket::Send(const Aws::String bucket_name, const Aws::String file_name, const Aws::String object_key) {
    Aws::S3::S3Client s3_client(config);

    std::cout << "Uploading " << file_name << " to S3 bucket " <<
        bucket_name << " with key " << object_key << std::endl;

    std::ifstream file_stream(file_name.c_str(), std::ios::in | std::ios::binary);
    if (!file_stream)
    {
        std::cout << "Failed to open file: " << file_name << std::endl;
        return 1;
    }

    Aws::S3::Model::PutObjectRequest object_request;
    object_request.SetBucket(bucket_name);
    object_request.SetKey(object_key);

    // Binary files must also have the std::ios_base::bin flag or'ed in
    auto input_data = Aws::MakeShared<Aws::FStream>("SampleAllocationTag",
        file_name.c_str(), std::ios_base::in | std::ios_base::binary);
    object_request.SetBody(input_data);

    auto put_object_outcome = s3_client.PutObject(object_request);

    if (put_object_outcome.IsSuccess())
    {
        std::cout << "Done!" << std::endl;
    }
    else
    {
        std::cout << "PutObject error: "
            << put_object_outcome.GetError().GetExceptionName() << std::endl;
        return 1;
    }

    return 0;
}
