package ray.channelBravo.mapper;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.context.annotation.Configuration;

@MapperScan(basePackages = {"ray.channelBravo.mapper"})
@Configuration
public class MyBatisConfig {
}
