#define BOOST_TEST_MODULE DriverTests
#include <boost/test/unit_test.hpp>

#include <iostream>

#include "i2s_mems_mic.h"

BOOST_AUTO_TEST_CASE(OPEN_PCM_TEST)
{
    I2Smic mic;
    mic.open_pcm();
    BOOST_CHECK_EQUAL(0, mic.get_rc());
}

BOOST_AUTO_TEST_CASE(PCM_SET_PARAMS_TEST)
{
    I2Smic mic;
    mic.open_pcm();
    mic.set_params();

    BOOST_CHECK_EQUAL(0, mic.get_rc());
}


BOOST_AUTO_TEST_CASE(SND_PCM_INTERNAL_FUNCTIOM_TEST)
{
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    BOOST_CHECK_EQUAL(0,snd_pcm_open(&handle, "plughw:1",SND_PCM_STREAM_CAPTURE, 0));

    /* allocate a hardware params obj  */
    snd_pcm_hw_params_alloca(&params);
    int err;
    
    //snd_pcm_hw_params_alloca(&params); 
    err = snd_pcm_hw_params_any(handle, params);
    BOOST_CHECK_EQUAL(0, err);

    err = snd_pcm_hw_params_set_access(handle, params,SND_PCM_ACCESS_RW_INTERLEAVED); 
    BOOST_CHECK_EQUAL(0, err);

    err = snd_pcm_hw_params_set_format(handle, params,hwparams.format);
    BOOST_CHECK_EQUAL(0, err);

    err = snd_pcm_hw_params_set_channels(handle, params, hwparams.channels);
    BOOST_CHECK_EQUAL(0, err);

    err = snd_pcm_hw_params_set_rate_near(handle, params, &hwparams.rate, 0);
    BOOST_CHECK_EQUAL(0, err);

    snd_pcm_uframes_t frames = 1024;
    err = snd_pcm_hw_params_set_period_size_near(handle, params, &frames, 0);
    BOOST_CHECK_EQUAL(0, err);

    err = snd_pcm_hw_params(handle, params);
    BOOST_CHECK_EQUAL(0, err);

    snd_pcm_hw_params_get_period_size(params, &frames, 0);
    BOOST_CHECK_EQUAL(0, err);

    unsigned int val;
    snd_pcm_hw_params_get_period_time(params, &val, 0);
    BOOST_CHECK_EQUAL(0, err);
}
