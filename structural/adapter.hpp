#pragma once

#include <memory>

namespace structural {

class ApiInterface {
public:
    virtual void run() const = 0;
};

class DemoApi : public ApiInterface {
public:
    void run() const override;
};

class LagacyApi {
public:
    void go() const;
};

class LagacyAdapter : public ApiInterface {
public:
    LagacyAdapter();

    void run() const override;
private:
    std::unique_ptr<LagacyApi> lagacy_api;
};

class LagacyClassAdapter : public ApiInterface, private LagacyApi {
    void run() const override;
};

} // structural end