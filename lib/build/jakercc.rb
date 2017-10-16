
# Class with around building things
class JakeRCC


  def self.run3_dont_fail(command, cd = nil, env = {})
    set_list = []
    env.each_pair do |k, v|
      if RUBY_PLATFORM =~ /(win|w)32$/
        set_list << "set \"#{k}=#{v}\"&&"
      else
        set_list << "export #{k}=#{v}&&"
      end
    end

    to_print = "CMD: #{command}"
    to_run = set_list.join('') + command
    if !cd.nil?
      to_print = "PWD: #{cd}\n#{to_print}"

      if RUBY_PLATFORM =~ /(win|w)32$/
        cd_ = cd.gsub('/', "\\")
        to_run = "cd /d \"#{cd_}\"&&#{to_run}"
      else
        to_run = "cd '#{cd}'&&#{to_run}"
      end
    end

    if !env.nil?
      to_print = "ENV: #{env}\n#{to_print}"
    end

    system(to_run)
  end

  def self.run3(command, cd = nil, env = {})
    fail "[#{command}]" unless self.run3_dont_fail(command, cd, env)
  end


end
