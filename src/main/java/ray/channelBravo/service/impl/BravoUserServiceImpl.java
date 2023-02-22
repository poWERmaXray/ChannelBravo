package ray.channelBravo.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ray.channelBravo.bean.BravoUser;
import ray.channelBravo.mapper.BravoUserMapper;
import ray.channelBravo.service.BravoUserService;

@Service
public class BravoUserServiceImpl implements BravoUserService {

    @Autowired
    private BravoUserMapper bravoUserMapper;

    @Override
    public Long singUp(BravoUser user) {
        return bravoUserMapper.registerBravoUser(user);
    }
}
