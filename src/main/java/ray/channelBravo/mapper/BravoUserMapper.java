package ray.channelBravo.mapper;

import org.apache.ibatis.annotations.Mapper;
import ray.channelBravo.bean.BravoUser;

@Mapper
public interface BravoUserMapper {
    /**
     * 注册用户
     */
    Long registerBravoUser(BravoUser user);
}
